//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayBag.
    @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>
#include <iostream>

/*
  the implementation checks if bag is empty and or item is not found first.
  If none of the above it exits returning false.
  If found the replacemnt is performed
*/

template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType& oldEntry,const ItemType& newEntry)
{
  if (!isEmpty()) {
    int locatedIndex = getIndexOf(oldEntry);
    if (locatedIndex > -1){
      items[locatedIndex] = newEntry;
      return true; // Item found and replaced
    }
    else
      return false; // matching item not found
  }
  else
    return false; // fast exit if empty
}  // end replace

template<class ItemType>
ArrayBag<ItemType>::ArrayBag():
  itemCount(0),
  maxItems(DEFAULT_CAPACITY),
  items(new ItemType[DEFAULT_CAPACITY]){
  cout << "constructor default for size " << DEFAULT_CAPACITY << endl;
}  // end default constructor

// Explicit capcity constructor
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(int capacity):
  itemCount(0),
  maxItems(capacity),
  items(new ItemType[capacity]){
  cout << "constructor explicit for size " << capacity << endl;
} // end explicit capacity constructor

template<class ItemType>
ArrayBag<ItemType>::~ArrayBag(){
  delete[] items;
  items = nullptr;
  cout << "destruct" << endl;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
    {
      items[itemCount] = newEntry;
      itemCount++;
    }  // end if

	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
  int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
    {
      itemCount--;
      items[locatedIndex] = items[itemCount];
    }  // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
  int frequency = 0;
  int curIndex = 0;       // Current array index
  while (curIndex < itemCount)
    {
      if (items[curIndex] == anEntry)
        {
          frequency++;
        }  // end if

      curIndex++;          // Increment to next entry
    }  // end while

  return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
  vector<ItemType> accumulator; // declare accumulator
  return toVectorR(0, accumulator); // pass accumulator to collect values into 
}  // end toVector

// private
template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVectorR( int currentIndex, vector<ItemType>& accumulator) const
{
  if (currentIndex < getCurrentSize()){
    accumulator.push_back(items[currentIndex]); // push an item to accumulator
    return toVectorR(currentIndex + 1, accumulator); // call self with incremented index
  } else {
    return accumulator; // return accumulator vector - we are done!
  }  // end if
}


// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
  int result = -1;
  int searchIndex = 0;
  // If the bag is empty, itemCount is zero, so loop is skipped
  while (!found && (searchIndex < itemCount))
    {
      if (items[searchIndex] == target)
        {
          found = true;
          result = searchIndex;
        }
      else
        {
          searchIndex++;
        }  // end if
    }  // end while

  return result;
}  // end getIndexOf
