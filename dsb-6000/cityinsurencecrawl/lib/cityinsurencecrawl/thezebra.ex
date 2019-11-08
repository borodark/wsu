defmodule TheZebra do
  @behaviour Crawly.Spider
  # Crawly.Engine.start_spider(TheZebra) 
  require Logger
  @impl Crawly.Spider
  def base_url(), do: "https://www.thezebra.com/"

  @impl Crawly.Spider
  def init() do
    [
      start_urls: [
        "https://www.thezebra.com/auto-insurance/car-insurance-rates-city/"
      ]
    ]
  end

  ## city_data |> Enum.map(&TheZebra.parse_rates/1) |> Enum.filter(fn %{"key" => value} -> not MapSet.member?(MapSet.new(["Credit Quality","Average Car Insurance Rate","Age","Average Rate","Marital Status/Gender"]),value); %{"value" => value} -> true  end)
  ## {"td", [], ["City Average"]},
  ## Type II page with horizontal tables
  def parse_rates({"td", [], ["$" <> value]}) do
    {rate_int, ""} =
      value
      |> String.replace(",", "")
      |> Integer.parse()

    %{"value" => rate_int}
  end

  def parse_rates({"td", [], [label]}) do
    %{"key" => label}
  end

  def parse_rates({"td", [{"style", "width: 50%;"}], ["$" <> value]}) do
    {rate_int, ""} =
      value
      |> String.replace(",", "")
      |> Integer.parse()

    %{"value" => rate_int}
  end

  def parse_rates({"td", [{"style", "width: 50%;"}], [label]}) do
    %{"key" => label}
  end

  def parse_rates({"li", [], [text]}) do
    [rate_column, rate_value] =
      text
      |> String.split(": $")

    {rate_int, _} =
      rate_value
      |> String.replace(",", "")
      |> Integer.parse()

    %{rate_column => rate_int}
  end

  def parse_rates({"li", [_], [_]}) do
    :ok
  end

  @impl Crawly.Spider
  def parse_item(response) do
    # Extracting pagination urls
    city_url_tuples =
      response.body
      |> Floki.find("td a")
      |> Enum.map(fn {"a", [{_, ref}], [city]} -> {city, ref} end)

    cities =
      city_url_tuples
      |> Enum.map(fn {city, _} -> city end)

    urls =
      city_url_tuples
      |> Enum.map(fn {_, url} -> url end)

    # Converting URLs into Crawly requests

    requests =
      urls
      |> Enum.map(&build_absolute_url/1)
      |> Enum.map(&Crawly.Utils.request_from_url/1)

    # TODO grab city for type II
    # "How Much Does Car Insurance Cost in "<>"Anchorage"<>"?"
    # "Car Insurance in "<>"Renton"
    # "How Much Are Car Insurance Rates in "<>city<>"?"
    h2z =
      response.body
      |> Floki.find("h2")

    city =
      h2z
      |> (fn
            [] -> ""
            [one | _] -> one
          end).()
      |> Floki.text()
      |> parse_city

    # TODO parse city if subsrings found in cities
    rates_map = Map.new()
    # [of maps]
    ## Type I https://www.thezebra.com/lafayette-la-car-insurance/
    rates_I =
      response.body
      |> Floki.find("div.blog-content-block ul li")
      |> Enum.map(fn x -> parse_rates(x) end)
      |> Enum.filter(fn x -> x != :ok end)
      |> Enum.reduce(rates_map, fn x, acc -> Map.merge(acc, x) end)
    #
    ## Type II https://www.thezebra.com/lafayette-la-car-insurance/
    rates_II =
      response.body
      |> Floki.find("tr td")
      |> Enum.map(fn x -> parse_rates(x) end)
      |> Enum.filter(fn x -> filter_type_II(x) end)

    %Crawly.ParsedItem{
      :items => [
        %{
          city: city,
          rates: rates_II ++ rates_I
        }
      ],
      :requests => requests
    }
  end

  def filter_type_II(%{"key" => value}) do
    not MapSet.member?(
      MapSet.new([
        "Credit Quality",
        "Average Car Insurance Rate",
        "Age",
        "Average Rate",
        "Marital Status/Gender",
        "Incident or Violation"
      ]),
      value
    )
  end

  def filter_type_II(%{"value" => _}), do: true

  def parse_city("What's the Cost of Car Insurance in " <> a_city?),
    do: a_city? |> String.trim_trailing("?")

  def parse_city("How Much Does Auto Insurance Cost in " <> a_city?),
    do: a_city? |> String.trim_trailing("?")

  def parse_city("How Much Does Car Insurance Cost in " <> a_city?),
    do: a_city? |> String.trim_trailing("?")

  def parse_city("How Much Are Car Insurance Rates in " <> a_city?),
    do: a_city? |> String.trim_trailing("?")

  def parse_city("What's the Average Cost of Car Insurance in " <> a_city?),
    do: a_city? |> String.trim_trailing("?")

  def parse_city("How Much Does Providence, RI, Car Insurance Cost?"),
    do: "Providence"

  def parse_city("How much does car insurance cost in Lexington, Kentucky?"),
    do: "Lexington"

  def parse_city("Car Insurance in " <> city), do: city

  def parse_city("Car insurance rates by city"), do: :ok

  def parse_city(_), do: :ok

  defp build_absolute_url(url), do: URI.merge(base_url(), url) |> to_string()
end
