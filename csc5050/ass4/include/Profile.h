/**  Profile.h
     Define attributes and behaviour for not yet TheFaceBooks social network member 
*/

#ifndef _PROFILE
#define _PROFILE

#include <string>

class Node;

enum Status { single, rel, complicated };

using namespace std;

class Profile {
 private:
  string name; // A data about Profile
  string picture; // ;-) or :-) or &-)
  Status status;
  Node* memberPtr; // Pointer to the member owning thias profile 

 public:
  Profile();
  Profile(const string name,const string picture, const Status status);
  const string getName();
  const string getPicture(); 
  const Status getStatus();
  const bool isMember();
 // TODO print , etc
}; // end Profile

#include "Profile.cpp"
#endif
