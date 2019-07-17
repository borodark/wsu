#include <cctype>
#include <string>

using namespace std;

Node::Node(Profile* aProfile) : profile(aProfile)
{
  id = this->profile->getName();
  this->profile->setMember(this);
} // end default constructor

Node::~Node()
{
  profile = nullptr;
  // TODO delete friends;
} // end default constructor

// TODO Accessors, print , etc 

Profile* Node::getProfile() const {
  return profile;
}

string Node::getId() const {
  return id;
}

list<Node*> Node::getFriends() const {
  return friends;
}

const string Node::printFriends() const {
  string rc = " has " + to_string(friends.size()) + " friends -> [";
  // TODO print all names
  //  for ( size_t i = 0; i < friends.size(); ++i )
  //rc += friends.get(i)->getName() + ",";
  rc+="]";
  return rc;
}

const string Node::print() const 
{
  string friends = printFriends();
  return "Member" + getProfile()->print() + ". "+ friends;
}
