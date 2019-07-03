//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Header file for an array-based implementation of the ADT bag.
    @file ArrayBag.h */

#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
 private:
	static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType *items = nullptr;      // Keep the pointer too
	// items = new ItemType[DEFAULT_CAPACITY];      // Array of bag items

  int itemCount;                         // Current count of bag items 
  int maxItems;                          // Max capacity of the bag

  // Returns either the index of the element in the array items that
  // contains the given target or -1, if the array does not contain 
  // the target.
  int getIndexOf(const ItemType& target) const;
  // Recursive toVectorR helper function
  vector <ItemType> toVectorR( int currentIndex, vector<ItemType>& accumulator) const;

 public:
	ArrayBag();
	ArrayBag(int capacity); // new constructor to ensure capacity is enougth to copy
  ~ArrayBag(); // destructor to deallocate array
  bool replace(const ItemType& oldEntry, const ItemType& newEntry);
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
  vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
