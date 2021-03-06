/**  Profile.h
     Define attributes and behaviour for not yet TheFaceBooks social network member 
*/

#ifndef _PROFILE
#define _PROFILE

#include <string>

class TFBMember;
class TheFaceBooks;

enum Status { single = 0 , rel, comp };
const char *statuses[] = { "Single", "In Relationship", "It\'s complicated" };

using namespace std;

class Profile {

  friend class TheFaceBooks;
  friend class TFBMember;

 private:
  string name; // A data about Profile
  string picture; // ;-) or :-) or &-)
  Status status;
  const TFBMember* memberPtr; // Pointer to the member owning thias profile 
  void setMember(const TFBMember* aMemberPtr);

 public:
  Profile();
  Profile(const string name,const string picture, const Status status);
  ~Profile();
  const string getName() const;
  void setName(string newOne);
  const string getPicture() const; 
  void setPicture(string newOne);
  const Status getStatus() const;
  void setStatus(Status newOne);
  const bool isMember() const;
  const string print() const;
}; // end Profile

#include "Profile.cpp"
#endif
