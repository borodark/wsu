/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a TheFacebooks interface implementationfor Question 3 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/include/TheFaceBooks.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/
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

TFBMember* TheFaceBooks::joinTFB(Profile* nub){
  TFBMember* rc = new TFBMember(nub);
  members.push_back(rc); // add to "global" list of members
  return rc;
}

list<TFBMember*> TheFaceBooks::search(string nameOrPicture){
  list<TFBMember*> rc;
  for (auto it=members.cbegin(); it != members.cend(); ++it) {
    const Profile * p = (*it)->getProfile();
    if((p->getName() == nameOrPicture)||(p->getPicture() == nameOrPicture)){
      rc.push_back((*it));
    }
    p= nullptr;
  }
  return rc;
}

void TheFaceBooks::deleteProfile(Profile* aProfile){
  aProfile->setMember(nullptr);
  profiles.remove(aProfile); // remove from "global" list of profiles
  delete aProfile;
  aProfile = nullptr;
  cout << "Profile delete exits." << endl;

}

void TheFaceBooks::leaveTFB(TFBMember* looser){
  members.remove(looser); // remove from "global" list of members
  delete looser; // Destructor is called
  looser = nullptr;
}

void TheFaceBooks::beFriend(TFBMember* me, TFBMember* bff){
  me->addFriend(bff);
  bff->addFriend(me);
}

void TheFaceBooks::unFriend(TFBMember* me, TFBMember* bff_not){
  me->removeFriend(bff_not);
  bff_not->removeFriend(me);
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
