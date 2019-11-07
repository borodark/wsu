defmodule TheZebra do
  @behaviour Crawly.Spider

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

  def parse_rates({"li", [], [text]}) do
    [rate_column,rate_value] =
      text
      |> String.split(": $")
    {rate_int,_} =
      rate_value
      |> String.replace(",","")
      |> Integer.parse
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
      |> Enum.map(fn {"a", [{_,ref}],[city]} -> {city, ref} end)

    cities =
      city_url_tuples
      |> Enum.map(fn {city, _} -> city end )

    urls =
      city_url_tuples
      |> Enum.map(fn {_, url} -> url end )
    # Converting URLs into Crawly requests

    requests =
      urls
      |> Enum.map(&build_absolute_url/1)
      |> Enum.map(&Crawly.Utils.request_from_url/1)

    city =
      response.body
      |> Floki.find("h1.blog-headline")
      |> Floki.text
    # TODO parse city if subsrings found in cities
    rates_map = Map.new
    rates = # [of maps]
      response.body
      |> Floki.find("div.blog-content-block ul li")
      |> Enum.map(fn x -> parse_rates(x) end)
      |> Enum.filter(fn x -> x != :ok end)
      |> Enum.reduce(rates_map,fn x, acc -> Map.merge(acc,x) end)
    # 
    %Crawly.ParsedItem{
      :items => [
        %{
          city: city,
          rates: rates
        }
      ],
      :requests => requests
    }
  end

  defp build_absolute_url(url), do: URI.merge(base_url(), url) |> to_string()

end
