curl -v -k 'https://35.224.130.80/solr/wsu/update/json/docs?split=/exams&f=first:/first&f=last:/last&f=grade:/grade&f=subject:/exams/subject&f=test:/exams/test&f=marks:/exams/marks' \
    -H 'Content-type:application/json' -d '
{
  "first": "John",
  "last": "Doe",
  "grade": 8,
  "exams": [
    {
      "subject": "Maths",
      "test"   : "term1",
      "marks"  : 90},
    {
      "subject": "Biology",
      "test"   : "term1",
      "marks"  : 86}
  ]
}' \
    -u ${SOLR_CREDS}
