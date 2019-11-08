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
    city_urls =
      response.body
      |> Floki.find("tbody tr td a")

    Logger.debug("#{inspect(city_urls)}")

    urls =
      if city_urls == [] do
        []
      else
        city_urls
        |> Enum.map(fn {"a", [{_, ref}], [_city]} -> ref end)
      end

    # Converting URLs into Crawly requests

    Logger.debug("#{inspect(urls)}")

    requests =
      urls
      |> Enum.map(&build_absolute_url/1)
      |> Enum.map(&Crawly.Utils.request_from_url/1)

    # .blog-content-block h2 # Rockport
    # .zip-content div h2 # Kansas
    city_list = response.body |> Floki.find(".blog-content-block h2")
    #   Logger.debug("City List: #{inspect(city_list)}")

    h2z =
      if city_list == [] do
        response.body |> Floki.find(".zip-content div h2")
      else
        city_list
      end

    city =
      h2z
      |> (fn
            [] -> ""
            [one | _] -> one
          end).()
      |> Floki.text()
      |> parse_city

    Logger.debug("City: #{inspect(city)}")

    # TODO parse city if subsrings found in cities
    rates_map = Map.new()
    # [of maps]
    rates_raw =
      response.body
      |> Floki.find(".blog-content-block ul li")
      ## Type I https://www.thezebra.com/lafayette-la-car-insurance/
      |> Floki.filter_out(".social-icons-list-item")

#    Logger.debug("Rates Raw: #{inspect(rates_raw)}")

    rates =
      if rates_raw == [] do
        rates_II =
        response.body
        ## Type II https://www.thezebra.com/anchorage-ak-car-insurance/
        |> Floki.find(".col-lg-9 tr td") # .col-lg-9 tr td
        |> Enum.map(fn x -> parse_rates(x) end)
        |> Enum.filter(fn x -> filter_type_II(x) end)
        # TODO

        six = rates_II |> Enum.take(6)
        Logger.debug("Six: #{inspect six}")
        rates_rc  =
        if six != [] do
          [%{"key" => k1},
           %{"key" => k2},
           %{"key" => k3},
           %{"value" => v1},
           %{"value" => v2},
           %{"value" => v3}] = six
          %{k1 => v1, k2 => v2, k3 => v3}
        else
          %{}
        end
        rates_rc
      else
        ## we R on the first page with list of urls for the cityes
        if city == :ok do
          # we R on the first page with list of urls for the cityes
          []
        else
          rates_raw
          |> Enum.map(fn x -> parse_rates(x) end)
          |> Enum.filter(fn x -> x != :ok end)
          |> Enum.reduce(rates_map, fn x, acc -> Map.merge(acc, x) end)
        end
      end

    Logger.debug("Rates: #{inspect(rates)}")

    items =
    if rates == [] do
      %{
        city: city
      }
    else
      %{
        city: city
      } |> Map.merge(rates)
    end


    %Crawly.ParsedItem{
      :items => [
      items
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
