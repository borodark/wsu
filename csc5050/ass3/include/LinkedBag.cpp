//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
//#include <iostream>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
  Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
  if (origChainPtr == nullptr)
    headPtr = nullptr;  // Original bag is empty
  else
    {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
        {
          // Get next item from original chain
          ItemType nextItem = origChainPtr->getItem();
         
          // Create a new node containing the next item
          Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
          // Link new node to end of new chain
          newChainPtr->setNext(newNodePtr);
         
          // Advance pointer to new last node
          newChainPtr = newChainPtr->getNext();
         
          // Advance original-chain pointer
          origChainPtr = origChainPtr->getNext();
        }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
  clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
  // Add to beginning of chain: new node references rest of chain;
  // (headPtr is null if chain is empty)        
  Node<ItemType>* nextNodePtr = new Node<ItemType>();
  nextNodePtr->setItem(newEntry);
  nextNodePtr->setNext(headPtr);  // New node points to chain
  //   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

  headPtr = nextNodePtr;          // New node is now first node
  itemCount++;
   
  return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
  vector<ItemType> bagContents;
  Node<ItemType>* curPtr = headPtr;
  int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
    {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
    }  // end while
   
  return bagContents;
}  // end toVector

template<class ItemType>
void LinkedBag<ItemType>::reverseLoop()
{
  Node<ItemType>* hPtr = headPtr;
  Node<ItemType>* curPtr = hPtr->getNext();
  headPtr = nullptr;
  int counter = 0;
  bool atTheEnd = false;
	while ((!atTheEnd)&&(counter < itemCount))
    {
      Node<ItemType>* tmpPtr = curPtr->getNext(); // save next
      if(counter == 0) // at the head - special case
        {
          hPtr->setNext(nullptr); // former head node - set next to nullpointer
          //to not break the semmantics of the proper linked bag
          curPtr->setNext(hPtr); // fix the next to former head
          hPtr = nullptr; // free  
          hPtr = curPtr; // swap
          curPtr = tmpPtr; // advance
          tmpPtr = nullptr; //clear
        }
      else
        {
          if(tmpPtr != nullptr) // in between 
            {
              curPtr->setNext(hPtr); // fix the next to former head
              hPtr = nullptr; // free  
              hPtr = curPtr; // swap
              curPtr = tmpPtr; // advance
              tmpPtr = nullptr; //clear
            } else // last node
            {
              atTheEnd = true;// exit loop 
              curPtr->setNext(hPtr); // fix the next to former head
              headPtr = curPtr; // keep the the head
              tmpPtr = nullptr; //clear
            }
        }
      counter++;
    }  // end while
  hPtr = nullptr; // free  
  curPtr = nullptr; // free 

}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
  Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
  bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
  if (canRemoveItem)
    {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
    } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
  Node<ItemType>* nodeToDeletePtr = headPtr;
  while (headPtr != nullptr)
    {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
    }  // end while
  // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
  int counter = 0;
  Node<ItemType>* curPtr = headPtr;
  while ((curPtr != nullptr) && (counter < itemCount))
    {
      if (anEntry == curPtr->getItem())
        {
          frequency++;
        } // end if
      
      counter++;
      curPtr = curPtr->getNext();
    } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains


/**
   makes left -> rigft -> far_right to left <- rigft
   returns pointer to far_right
*/

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::reverse(Node<ItemType>* curPtr,
                                                  Node<ItemType>* nextPtr)
{
  Node<ItemType>* result = nullptr;
  if (nextPtr == nullptr){ // we reached the tail
    result = curPtr; // curPtr becomes the headPtr
  } else {
    Node<ItemType>* nextOfTheNext = nextPtr->getNext(); // extract the next of the next
    nextPtr->setNext(curPtr);
    result = reverse(nextPtr, nextOfTheNext);
  } // end if
  return result;
}  // end 

template<class ItemType>
void LinkedBag<ItemType>::reverseRecursion()
{
  Node<ItemType>* head = headPtr;
  headPtr = nullptr;
  Node<ItemType>* nextToHead = head->getNext();
  head->setNext(nullptr);
  headPtr = reverse(head, nextToHead); 
}

template<class ItemType>
bool LinkedBag<ItemType>::replace(const ItemType& oldEntry,const ItemType& newEntry)
{
  // TODO Impelent
  return false; // Stubbed
}
/**
   As the assignment does not state the return type of the removeDuplicates function
   I took a liberty to return a new LinkedBag without duplicates.
   All pointers should be dereferenced and nodes deleted.
   It is still n^2 but the memory should shrink while duplicates freed.
 */
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::removeDuplicates()
{
  LinkedBag<ItemType> rc;
  Node<ItemType>* hPtr = headPtr;
  rc.add(hPtr-> getItem());
  delete headPtr;
  headPtr = nullptr;
  int counter = 0;
  bool atTheEnd = false;
	while ((!atTheEnd)&&(counter < itemCount))
    {
      Node<ItemType>* node = hPtr->getNext();
      ItemType v = node->getItem();
      if(!rc.contains(v)){
        rc.add(v);
      }
      hPtr = node->getNext();
      if( hPtr == nullptr){
        atTheEnd = true;
      }
      counter++;
      delete node;
      node = nullptr;
    }  // end while
  delete hPtr;
  hPtr =  nullptr;
  return rc;
}


// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
  bool found = false;
  Node<ItemType>* curPtr = headPtr;
  while (!found && (curPtr != nullptr))
    {
      if (anEntry == curPtr->getItem())
        found = true;
      else
        curPtr = curPtr->getNext();
    } // end while
   
  return curPtr;
} // end getPointerTo


