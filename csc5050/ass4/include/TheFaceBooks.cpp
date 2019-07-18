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
  Profile* rc = new Profile(name, picture, status);
  profiles.push_back(rc); // add to "global" list of profiles
  return rc;
}

Node* TheFaceBooks::joinTFB(Profile* nub){
  Node* rc = new Node(nub);
  members.push_back(rc); // add to "global" list of members
  return rc;
}

void TheFaceBooks::deleteProfile(Profile* aProfile){
  profiles.remove(aProfile); // remove from "global" list of profiles
}

void TheFaceBooks::leaveTFB(Node* looser){
  members.remove(looser); // remove from "global" list of members
}

const string TheFaceBooks::printMembers() const {
  string rc = " TFB has " + to_string(members.size()) + " members -> [\n";
  int i = 1;
  for (auto it=members.cbegin(); it != members.cend(); ++it) {
    rc+= to_string(i) + ". " + (*it)->print() + ",\n";
    i++;
  }
  rc+="]";
  return rc;
}

const string TheFaceBooks::printProfiles() const {
  string rc = " TFB has " + to_string(profiles.size()) + " Profiles ->  [\n";
  int i = 1;
  for (auto it=profiles.cbegin(); it != profiles.cend(); ++it) {
    rc+= to_string(i) + ". " + (*it)->print() + ",\n";
    i++;
  }
  rc+="]";
  return rc;
}
