curl -k "https://35.224.130.80/solr/wsu/update?commit=true" -H "Content-Type: application/json" --data-binary '{"delete": {"query":"*:*"}}' -u ${SOLR_CREDS}
