
# CS5050 Assignment 4

## To run

Developed and tested in Mac OSX 

Install `cmake` and `make` , pull this repo change to this directory, run:

`cmake .` to create Makefile

`make` to comple


## Q1

Using stacks, write a [non-recursive function solveTowers( )](src/q1.cpp#L56) to solve the towers of Hanoi problem. Furthermore, implement a driver file to test your code. (2 points)

* [src/q1.cpp](src/q1.cpp) - driver and implementation
* Results: [q1.out](q1.out)

I have also impweHighlights:

  
## Q2

* Q2 - [src/q2.cpp](src/q2.cpp) driver
* Results: [q2.out](q2.out)

Write an array-based implementation of the ADT list that expands the size of the array of list entries as needed so that the list can always accommodate a new entry. (2 points)

* The [include/ArrayList.h](include/ArrayList.h) defines  behaviour
* The [include/ArrayList.cpp](include/ArrayList.cpp) provides implementation

The expand is implementated here: [include/ArrayList.cpp](include/ArrayList.cpp#L42) and used during 
* insert [include/ArrayList.cpp](include/ArrayList.cpp#L81) 
* setEntry [include/ArrayList.cpp](include/ArrayList.cpp#L136) 

## Q3

The popular social network Facebook was founded by Mark Zuckerberg and his classmates at Harvard University in 2004. At the time, he was a sophomore studying computer science.

### Design and implement an application that maintains the data for a simple social network.

* _The implentation is provided as library, no UI provided_. 
* All testing is done from the driver: [src/q3.cpp](src/q3.cpp). 
  * See output [q3.out](q3.out)

#### Each person in the network should have a profile that contains the person’s name, optional image, current status, and a list of friends. 

The profile can be created without joining:
* The [include/Profile.h](include/Profile.h) defines  behaviour
* The [include/Profile.cpp](include/Profile.cpp) provides implementation

The _Member_ encapsulates the [Profile](include/TFBMember.h#L18) and the [list of friends](include/TFBMember.h#L20)
* The [include/TFBMember.h](include/TFBMember.h) defines  behaviour
* The [include/TFBMember.cpp](include/TFBMember.cpp) provides implementation


#### Your application should allow a user to join the network, leave the network, create a profile, modify the profile, search for other profiles, and add friends. (6 points)

* Interface [include/TheFaceBooks.h](include/TheFaceBooks.h) provide encapsulation of data and the public interface for:
   * createProfile [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L23)
   * deleteProfile [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L47)
   * joinTFB [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L29)
   * search [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L35)
   * leaveTFB [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L56)
   * beFriend [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L62)
   * unFriend [include/TheFaceBooks.cpp](include/TheFaceBooks.cpp#L67)

 
