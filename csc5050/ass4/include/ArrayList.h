//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/**
   Modified by  @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   for Question 2 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/include/ArrayBag.h
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

/** ADT list: Array-based implementation.
    Listing 9-1.
    @file ArrayList.h */

#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
 private:
	static const int DEFAULT_CAPACITY = 5; // Small capacity to test for a full list 

  static const int REVERSED_GROWS_FACTOR = 2; // to grow with max_items + maxItems/REVERSED_GROWS_FACTOR

	ItemType *items = nullptr;      // Keep the pointer too
  int itemCount;                         // Current count of list items 
  int maxItems;                          // Maximum capacity of the list
  void ensureCapacity(int newPosition);
 public:
  ArrayList();
  // Copy constructor and destructor are supplied by compiler
	explicit ArrayList(int capacity); // new constructor for dinamicly allocating array from constructor
  /**  Cause the array is allocated from heap with new the cleanup is manual */
  ~ArrayList();
  bool isEmpty() const;
  int getLength() const;
  bool insert(int newPosition, const ItemType& newEntry);
  bool remove(int position);
  void clear();

  /** @throw PrecondViolatedExcep if position < 1 or 
      position > getLength(). */
  ItemType getEntry(int position) const;

  /** @throw PrecondViolatedExcep if position < 1 or 
      position > getLength(). */
  void setEntry(int position, const ItemType& newEntry);
}; // end ArrayList

#include "ArrayList.cpp"
#endif 
