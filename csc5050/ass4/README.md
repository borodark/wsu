
# CS5050 Assignment 3

## To run

Developed and tested in Mac OSX 

Install `cmake` and `make` , pull this repo change to this directory, run:

`cmake .` to create Makefile

`make` to comple


## Q 1,2,3 4

### source code:

* Q1 - [src/q1.cpp](src/q1.cpp) - driver and implementation
  * Results: [q1.out](q1.out)
  
* Q2 - [src/q2.cpp](src/q2.cpp)  - driver and implementation
  * Results: [q2.out](q2.out)
  
## Q3
The popular social network Facebook was founded by Mark Zuckerberg and his classmates at Harvard University in 2004. At the time, he was a sophomore studying computer science.

* _The implentation is provided as library, no UI provided_. 
* All testing is done from the driver: [src/q3.cpp](src/q3.cpp). 
  * See output [q3.out](q3.out)

### Design and implement an application that maintains the data for a simple social network.

* Interface [include/TheFaceBooks.h](include/TheFaceBooks.h) provide encapsulation of data and the public interface for:
   * createProfile [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L23)
   * deleteProfile [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L47)
   * joinTFB [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L29)
   * search [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L35)
   * leaveTFB [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L56)
   * beFriend [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L62)
   * unFriend [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L67)

   const string printMembers() const;
   const string printProfiles() const;



### Each person in the network should have a profile that contains the person’s name, optional image, current status, and a list of friends. 
### Your application should allow a user to join the network, leave the network, create a profile, modify the profile, search for other profiles, and add friends. (6 points)

 