
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
Specify and implement an *ADT for fractions*: see [Fraction Header](include/Fraction.h) [Fraction Implementation](include/Fraction.cpp). Provide operations that [add](include/Fraction.cpp#L52), [subtract](include/Fraction.cpp#L62), multiply, and divide these numbers. The results of all arithmetic operations should be in lowest terms, so include a private function reduceToLowestTerms. To simplify the determination of a fraction’s sign, you can assume that the denominator of the fraction is positive. Next, Specify and implement an ADT for mixed numbers, each of which contains an integer portion and a fractional portion in lowest terms. You can utilize the ADT fraction you created in the first part of this problem. Provide operations that add, subtract, multiply, and divide mixed numbers. The results of all arithmetic operations should have fractional portions that are in the lowest terms. Also, include an operation that converts a fraction to a mixed number.

* Q3 - [src/q3.cpp](src/q3.cpp)   - driver and implementation
  * Modified ArrayBag interface, header,cpp - [include/](include/)
  * Results: [q3.out](q3.out)
  
  
* Q4 - [src/q4.cpp](src/q4.cpp)   - driver
  * Complex.h ,cpp - [include/](include/) Class declaration and implementation
  * Results: [q4.out](q4.out)
  



