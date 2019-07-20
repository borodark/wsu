//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/**
   Modified and possibly indented by  @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   for Question 2 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/include/ArrayList.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

/** Implementation file for the class ArrayList.
    @file ArrayList.cpp */

#include <iostream>
#include "ArrayList.h"  // Header file
using namespace std;

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0),
                                   maxItems(DEFAULT_CAPACITY),
                                   items(new ItemType[DEFAULT_CAPACITY]) {
  cout << "constructor default for size " << DEFAULT_CAPACITY << endl;
} // end default constructor

// Explicit capcity constructor
template<class ItemType>
ArrayList<ItemType>::ArrayList(int capacity):
  itemCount(0),
  maxItems(capacity),
  items(new ItemType[capacity]){
  cout << "constructor explicit for size " << capacity << endl;
} // end explicit capacity constructor

template<class ItemType>
ArrayList<ItemType>::~ArrayList(){
  delete[] items;
  items = nullptr;
  cout << "Destructing array list ..." << endl;
}

template<class ItemType>
void ArrayList<ItemType>::ensureCapacity(int newPosition) {
  // TODO?? throw std::bad_alloc
  bool ableToInsert = (newPosition >= 1)
    && (newPosition <= itemCount + 1)
    && (itemCount < maxItems);
  if (!ableToInsert) {
    cout << "Allocating ....";
    int newSize = newPosition + GROW_BY; // Add 5 to encure O(n) penalty only every 5 objects over capacity
    // trade off must be observed here
    // either O(n) penalty or pre alocate and not use the memory
    ItemType* newArray = new ItemType[newSize];
    int last = sizeof(&items)/sizeof(items);
    std::copy(items, items + last, newArray);
    delete [] items;
    items = nullptr;
    items = newArray;
    maxItems = newSize;
    cout << ". Done! the new size is: "
         << sizeof(items) * maxItems
         << ". The new maxItems is: "
         << maxItems << endl;
  }
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
  return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
  return itemCount;
}  // end getLength

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
  ensureCapacity(newPosition);
  // Make room for new entry by shifting all entries at
  // positions >= newPosition toward the end of the array
  // (no shift if newPosition == itemCount + 1)
  for (int pos = itemCount; pos >= newPosition; pos--)
    items[pos] = items[pos - 1];
  // Insert new entry
  items[newPosition - 1] = newEntry;
  itemCount++;  // Increase count of entries
  //}  // end if
  return true;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
  bool ableToRemove = (position >= 1) && (position <= itemCount);
  if (ableToRemove)
    {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array
      // (no shift if position == itemCount)
      for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount;
           fromIndex++, toIndex++)
        items[toIndex] = items[fromIndex];
      itemCount--;  // Decrease count of entries
    }  // end if
  return ableToRemove;
}  // end remove

template<class ItemType>
void ArrayList<ItemType>::clear()
{
  itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
  // Enforce precondition
  bool ableToGet = (position >= 1) && (position <= itemCount);
  if (ableToGet)
    return items[position - 1];
  else
    {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw std::logic_error(message);
    }  // end if
}  // end getEntry

template<class ItemType>
void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
  // Enforce precondition
  bool ableToSet = (position >= 1) && (position <= itemCount);
  if (ableToSet)
    items[position - 1] = newEntry;
  else
    {
      string message = "setEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw std::logic_error(message);
    }  // end if
}  // end setEntry
//  End of implementation file.
