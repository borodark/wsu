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

  @impl Crawly.Spider
  def parse_item(response) do
    # Extracting pagination urls
    cities_urls = response.body |> Floki.find("td a") |> Floki.attribute("href")
    # Converting URLs into Crawly requests
    requests =
      cities_urls
      |> Enum.map(&build_absolute_url/1)
      |> Enum.map(&Crawly.Utils.request_from_url/1)

    %Crawly.ParsedItem{
      :items => [
        %{
          city: "",
          rate: ""
        }
      ],
      :requests => requests
    }
  end

  defp build_absolute_url(url), do: URI.merge(base_url(), url) |> to_string()

end
