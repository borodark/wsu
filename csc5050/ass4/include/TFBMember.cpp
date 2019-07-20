#include <cctype>
#include <string>

using namespace std;

TFBMember::TFBMember(Profile* aProfile) : profile(aProfile)
{
  id = this->profile->getName();
  this->profile->setMember(this);
} // end default constructor

TFBMember::~TFBMember()
{
  cout << "Member "<< id << " is destroyed!" << endl;
  profile->setMember(nullptr);
  int i = 0;
  for (auto it=friends.cbegin(); it != friends.cend(); ++it) {
    (*it)->removeFriend(this);
    i++;
  }
  cout << "Member had "<< i << " friends!" << endl;
  profile  = nullptr;
} // end destructor

const Profile* TFBMember::getProfile() const {
  return profile;
}

string TFBMember::getId() const {
  return id;
}

list<TFBMember*> TFBMember::getFriends() const {
  return friends;
}

const TFBMember* TFBMember::addFriend(TFBMember* const aMember){
  friends.push_back(aMember);
  return aMember;
}

void TFBMember::removeFriend(TFBMember* const aMember){
  friends.remove(aMember);
}

const string TFBMember::printFriends() const {
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

const string TFBMember::print() const 
{
  string friends = printFriends();
  return "Member" + getProfile()->print() + ". \n"+ friends;
}
