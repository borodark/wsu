/**  Profile.h
     Define attributes and behaviour for not yet TheFaceBooks social network member 
*/

#ifndef _PROFILE
#define _PROFILE

#include <string>

class Node;
class TheFaceBooks;

enum Status { single = 0 , rel, comp };
const char *statuses[] = { "Single", "In Relationship", "It\'s complicated" };

using namespace std;

class Profile {

  friend class TheFaceBooks;
  friend class Node;

 private:
  string name; // A data about Profile
  string picture; // ;-) or :-) or &-)
  Status status;
  const Node* memberPtr; // Pointer to the member owning thias profile 
  void setMember(const Node* aMemberPtr);

 public:
  Profile();
  Profile(const string name,const string picture, const Status status);
  ~Profile();
  const string getName() const;
  const string getPicture() const; 
  const Status getStatus() const;
  const bool isMember() const;
  const string print() const;
}; // end Profile

#include "Profile.cpp"
#endif
