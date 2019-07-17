#include <cctype>
#include <string>

using namespace std;

Node::Node(Profile* aProfile) : profile(aProfile)
{
  id = this->profile->getName();
} // end default constructor

Node::~Node()
{
  profile = nullptr; // derefience 

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
