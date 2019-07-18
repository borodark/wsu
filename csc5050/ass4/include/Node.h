/**  Node.h
     Define behaviour for TheFaceBooks social network member 
 */

#ifndef _NODE
#define _NODE

#include <list>
#include <string>

#include "Profile.h"

using namespace std;

class Node {
  friend class TheFaceBooks;
 private:
   Profile* profile; // A data about Profile
   string id; // capitalized Name from profile
   list<Node*> friends; //list of network members that are friends
   const string printFriends() const;
   list<Node*> getFriends() const;
   const Node* addFriend(Node* const aMember);
   Node(Profile* aProfile); // constructor
   void removeFriend(Node* const aMember);

 public:
   Node(); // 
   ~Node(); // destructor
   const Profile* getProfile() const ;
   string getId() const;
   const string print() const;
}; // end Node

#include "Node.cpp"
#endif
