/**  Profile.h
     Define attributes and behaviour for not yet TheFaceBooks social network member 
*/

#ifndef _PROFILE
#define _PROFILE

#include <string>

class Node;

enum Status { single = 0 , rel, complicated };
const char *statuses[] = { "Single", "In Relationship", "It\'s complicated" };

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
  const string getName() const;
  const string getPicture() const; 
  const Status getStatus() const;
  const bool isMember() const;
  const string print() const;
 // TODO print , etc
}; // end Profile

#include "Profile.cpp"
#endif
