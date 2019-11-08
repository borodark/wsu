use Mix.Config

config :crawly,
  # The path where items are stored
  base_store_path: "data",
  pipelines: [
    Crawly.Pipelines.JSONEncoder
  ]
