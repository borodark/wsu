/**  TFBMember.h
     Define behaviour for TheFaceBooks social network member 
 */

#ifndef _TFBMEMBER
#define _TFBMEMBER

#include <list>
#include <string>

#include "Profile.h"

using namespace std;

class TFBMember {
  friend class TheFaceBooks;
 private:
   Profile* profile; // A data about Profile
   string id; // capitalized Name from profile
   list<TFBMember*> friends; //list of network members that are friends
   list<TFBMember*> getFriends() const;
   const TFBMember* addFriend(TFBMember* const aMember);
   //   const TFBMember* unFriend(TFBMember* const aMember);
   TFBMember(Profile* aProfile); // constructor
   void removeFriend(TFBMember* const aMember);

 public:
   TFBMember(); // 
   ~TFBMember(); // destructor
   const Profile* getProfile() const ;
   string getId() const;
   const string print() const;
   const string printFriends() const;

}; // end TFBMember

#include "TFBMember.cpp"
#endif
