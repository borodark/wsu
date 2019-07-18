/**  TheFaceBooks.h
     Define behaviour for TheFaceBooks social network member 
 */

#ifndef _FB
#define _FB

#include <list>
#include <string>

#include "Profile.h"
#include "Node.h"

using namespace std;

class TheFaceBooks {
 private:
   list<Node*> members; //list of all network members
   list<Profile*> profiles; //list of all network members

 public:
   TheFaceBooks(); // constructor
   ~TheFaceBooks(); // destructor
   Profile* createProfile(const string name,const string picture, const Status status);
   void deleteProfile(Profile* aProfile);
   Node* joinTFB(Profile* nub);
   void leaveTFB(Node* looser);
   void beFriend(Node* me, Node* bff);
   void unFriend(Node* me, Node* bff_not);

   const string printMembers() const;
   const string printProfiles() const;
};

#include "TheFaceBooks.cpp"
#endif
