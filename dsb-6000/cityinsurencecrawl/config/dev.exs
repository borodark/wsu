use Mix.Config

config :logger, :console, format: "[$level] $message\n"

config :crawly,
  # The path where items are stored
  base_store_path: "data",
  pipelines: [
    Crawly.Pipelines.JSONEncoder
  ]
