/**  TheFaceBooks.h
     Define behaviour for TheFaceBooks social network member 
 */

#ifndef _FB
#define _FB

#include <list>
#include <string>

#include "Profile.h"
#include "TFBMember.h"

using namespace std;

class TheFaceBooks {
 private:
   list<TFBMember*> members; //list of all network members
   list<Profile*> profiles; //list of all network members

 public:
   TheFaceBooks(); // constructor
   ~TheFaceBooks(); // destructor
   Profile* createProfile(const string name,const string picture, const Status status);
   void deleteProfile(Profile* aProfile);
   TFBMember* joinTFB(Profile* nub);
   list<TFBMember*> search(string nameOrPicture);
   void leaveTFB(TFBMember* looser);
   void beFriend(TFBMember* me, TFBMember* bff);
   void unFriend(TFBMember* me, TFBMember* bff_not);

   const string printMembers() const;
   const string printProfiles() const;
};

#include "TheFaceBooks.cpp"
#endif
