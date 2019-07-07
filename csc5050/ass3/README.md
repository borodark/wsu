
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
  
  * Specify and implement an *ADT for fractions*: see [Fraction Header](include/Fraction.h) [Fraction Implementation](include/Fraction.cpp). Provide operations that [add](include/Fraction.cpp#L52), [subtract](include/Fraction.cpp#L62), [multiply](include/Fraction.cpp#L71), and [divide](include/Fraction.cpp#L80) these numbers. The results of all arithmetic operations should be in lowest terms, so include a private function [reduceToLowestTerms](include/Fraction.cpp#L27). To simplify the determination of a fraction’s sign, you can assume that the denominator of the fraction is positive. Next, Specify and implement an ADT for mixed numbers: see  [MixedNumber Header](include/MixedNumber.h), [MixedNumber Implementation](include/MixedNumber.cpp) , each of which contains an integer portion and a fractional portion in lowest terms. You can utilize the ADT fraction you created in the first part of this problem. Provide operations that [add](include/MixedNumber.cpp#L43), [subtract](include/MixedNumber.cpp#L52), [multiply](include/MixedNumber.cpp#L64), and [divide](include/MixedNumber.cpp#L77) mixed numbers. The results of all arithmetic operations should have fractional portions that are in the lowest terms: see [void MixedNumber::reduce()](include/MixedNumber.cpp#L6). Also, include an operation that converts a fraction to a mixed number: see constructor that takes *Fraction* [MixedNumber::MixedNumber(const Fraction& f)](include/MixedNumber.cpp#L18).

* Q3 - [src/q3.cpp](src/q3.cpp)   - driver and implementation
  * Results: [q3.out](q3.out)
  * Modified ArrayBag interface, header,cpp - [include/](include/)
  * Modify the ArrayBag class: see [ArrayBag Header](include/ArrayBag.h) [ArrayBag Implementation](include/ArrayBag.cpp), given in Chapter 3 to meet the following specs:
    * Write a member function replace that replaces a given item in a given bag with another given item. The function should return a boolean value to indicate whether the replacement was successful: [bool ArrayBag<ItemType>::replace(const ItemType& oldEntry,const ItemType& newEntry)
](include/ArrayBag.cpp#L18). See trace: [q3.out#L6](q3.out#L6) of driver code starting here: [src/q3.cpp](src/q3.cpp#L61).
    * Write a recursive array-based implementation of the method [toVector](include/ArrayBag.cpp#L127) for the class ArrayBag. See helper function: [toVectorR](include/ArrayBag.cpp#L135) 
    * Write a client function that [merges](src/q3.cpp#L28) two bags into a new third bag. Do not destroy the original two bags. See trace here: [q3.out#L15](q3.out#L15)


  
  
* Q4 - [src/q4.cpp](src/q4.cpp)   - driver
  * [include/](include/) Classes declaration and implementation
  * Results: [q4.out](q4.out)
  * Write two _reverse_ functions for the linkedBag ADT: [LinkedBag Header](include/LinkedBag.h) [LinkedBag Implementation](include/LinkedBag.cpp), using both [iterative](include/LinkedBag.cpp#L106) and [recursive](include/LinkedBag.cpp#L228) approaches. The function is supposed to reverse the linked list data structure. See trace here: [reverse loop](q4.out#L1), [reverse recursive](q4.out#L6)
     
  * Also, write another function _removeDuplicates_ that will locate and remove any duplicates in the linked list (only one occurrence of each linked list entry is allowed): see here  [iterative](include/LinkedBag.cpp#L258). Test your functions using a driver program: [see trace here](q4.out#L12) 
  
  



