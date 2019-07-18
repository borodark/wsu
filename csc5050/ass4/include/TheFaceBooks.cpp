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

const list<Node*> TheFaceBooks::getMembers() const {
  return members;
}

const list<Profile*> TheFaceBooks::getProfiles() const {
  return profiles;
}

const string TheFaceBooks::printMembers() const {
  return "TODO";
}

const string TheFaceBooks::printProfiles() const {
  return "TODO";
}
