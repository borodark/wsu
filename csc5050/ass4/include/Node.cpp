#include <cctype>
#include <string>

using namespace std;

Node::Node(Profile* const aProfile) : profile(aProfile)
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

const Profile* Node::getProfile() const {
  return profile;
}

string Node::getId() const {
  return id;
}

list<Node*> Node::getFriends() const {
  return friends;
}

const Node* Node::addFriend(Node* const aMember){
  friends.push_back(aMember);
  return aMember;
}

const string Node::printFriends() const {
  string rc = " Has " + to_string(friends.size()) + " friends -> [\n";
  int i = 1;
  for (auto it=friends.cbegin(); it != friends.cend(); ++it) {
    // std::cout << ' ' << *it;
    rc+= to_string(i) + ". " + (*it)->getId() + ",\n";
    i++;
  }
  rc+="]";
  return rc;
}

const string Node::print() const 
{
  string friends = printFriends();
  return "Member" + getProfile()->print() + ". \n"+ friends;
}
