#include <cctype>
#include <string>

using namespace std;

TheFaceBooks::TheFaceBooks()
{
  // TODO init 
} // end default constructor

TheFaceBooks::~TheFaceBooks()
{
  // TODO delete all;
} // end default constructor

Profile* TheFaceBooks::createProfile(const string name,const string picture, const Status status){
  return (new Profile(name, picture, status));
}

bool TheFaceBooks::deleteProfile(Profile* aProfile){
  //TODO
  return true;
}

const string TheFaceBooks::printMembers() const {
  return "TODO";
}

const string TheFaceBooks::printProfiles() const {
  return "TODO";
}
