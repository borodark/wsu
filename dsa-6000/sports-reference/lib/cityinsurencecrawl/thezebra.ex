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

  def states_list do
    [
      "Alabama",
      "Alaska",
      "Arizona",
      "Arkansas",
      "California",
      "Colorado",
      "Connecticut",
      "Delaware",
      "Florida",
      "Georgia",
      "Hawaii",
      "Idaho",
      "Illinois",
      "Indiana",
      "Iowa",
      "Kansas",
      "Kentucky",
      "Louisiana",
      "Maine",
      "Maryland",
      "Massachusetts",
      "Michigan",
      "Minnesota",
      "Mississippi",
      "Missouri",
      "Montana",
      "Nebraska",
      "Nevada",
      "New Hampshire",
      "New Jersey",
      "New Mexico",
      "New York",
      "North Carolina",
      "North Dakota",
      "Ohio",
      "Oklahoma",
      "Oregon",
      "Pennsylvania",
      "Rhode Island",
      "South Carolina",
      "South Dakota",
      "Tennessee",
      "Texas",
      "Utah",
      "Vermont",
      "Virginia",
      "Washington",
      "West Virginia",
      "Wisconsin",
      "Wyoming",
      "Washington",
      "D.C"
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

    Logger.debug("CITY IS: #{inspect(city)}")
    # .zip-content.container.section-md  div  div p
    # body div.container div.row.blog-content-wrap.justify-content-center div.col-md-10.col-lg-7.col-xxl-6.blog-content-block p
    # body > main > section.zip-content.container.section-md > div > div > p:nth-child(3)
    # "body main section.zip-content.container.section-md div.raw div.col-lg-9 p"
    state_l =
      response.body
      |> Floki.find("body div p")
      |> Floki.text()
      |> String.split([" ", "'"])
      |> Enum.filter(fn word -> Enum.member?(states_list(), word) end)
      |> Enum.take(1)

    # par_state =
    #  if par_state == "" do
    #  else
    #    ""
    #  end
    state =
      if state_l != [] do
        [st | _] = state_l
        st
      else
        ""
      end

    # body div.container div.row.blog-content-wrap.justify-content-center div.col-md-10.col-lg-7.col-xxl-6.blog-content-block div.rich-text p

    Logger.debug("State paresd: #{inspect(state)} ")

    city_state =
      if state != "" do
        if city != :ok do
          city <> ", " <> state
        end
      else
        city
      end

    Logger.debug("City,State: #{inspect(city_state)}")

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
          # .col-lg-9 tr td
          |> Floki.find(".col-lg-9 tr td")
          |> Enum.map(fn x -> parse_rates(x) end)
          |> Enum.filter(fn x -> filter_type_II(x) end)

        # TODO

        {six, rest} = rates_II |> Enum.split(6)
        Logger.debug("Six: #{inspect(six)}")

        rates_rc =
          if six != [] do
            [
              %{"key" => k1},
              %{"key" => k2},
              %{"key" => k3},
              %{"value" => v1},
              %{"value" => v2},
              %{"value" => v3}
            ] = six

            %{k1 => v1, k2 => v2, k3 => v3}
          else
            %{}
          end

        Logger.debug("City is: #{inspect(city)}")

        ## TODO %{"key" => "City Average"}, %{"value" => 2814}, %{"key" => "City Average"}, %{"value" => 2814}],
        parse_kv(rates_rc, rest)
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

    #    Logger.debug("Rates: #{inspect(rates)}")

    items =
      if rates == [] do
        %{
          "city_comma_state" => city_state,
          "city" => city,
          "state" => state
        }
      else
        %{
          "city_comma_state" => city_state,
          "city" => city,
          "state" => state
        }
        |> Map.merge(rates)
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
        "Credit",
        "Credit Score",
        "Credit Quality",
        "Credit Level",
        "Average Car Insurance Rate",
        "Age",
        "Average Rate",
        "Mean Rate",
        "Marital Status",
        "Marital Status/Gender",
        "Violation/Incident",
        "Incident/Violation",
        "Incident or Violation",
        "Average Insurance Rate",
        "Average Annual Premium",
        "Average Auto Insurance Rate"
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

  ## take pairs of  %{"key" => "City Average"}, %{"value" => 2814}
  def parse_kv(acc, [key | [value | rest]]) do
    %{"key" => k} = key
    %{"value" => v} = value
    #    Logger.debug("#{inspect(rest)}")
    parse_kv(acc |> Map.merge(%{k => v}), rest)
  end

  def parse_kv(acc, []), do: acc

  defp build_absolute_url(url), do: URI.merge(base_url(), url) |> to_string()
end
