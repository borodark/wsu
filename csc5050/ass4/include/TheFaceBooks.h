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
   const list<Profile*> getProfiles() const ;
   const list<Node*> getMembers() const;
   const string printMembers() const;
   const string printProfiles() const;
};

#include "TheFaceBooks.cpp"
#endif
