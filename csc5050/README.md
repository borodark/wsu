# CS5050 Assignment 1

## Q 1,2, 4

Please see the ascicasts for two runs here
https://asciinema.org/a/248094

https://asciinema.org/a/248094

### source code:
Driver: ![src/assignment1.cpp](src/assignment1.cpp)
Employee ![include/](include/)


The `R` source for this report is: ![arima.R](arima.R)


## Question 3

On May 6, 2010, the prices of many equity products experienced an extraordinarily rapid decline and recovery , major equity indices in both the futures and securities markets, each already down over 4% from their prior-day close, plummeted a further 5-6% in a matter of minutes before rebounding quickly.
The cause of this events was Hight Frequency Traiding algorithm design. The HFT uses technique known as Arbitrage, sometimes, executing two legs of the trade on different exchanges: NY vs Chicago, etc. The algoritms uses techniques borowed form Automated Systems Control Theory: same principals many actual machines designed: watch the control variables and apply signals to actuators. The planes autopylots , self guided rockets uses these principals too. The fundamental problem is that systems may become unstable when the sarrounding conditions are close to the boundaries the system is intended to function, or sensors supply wrong information. 
The solutions used in the physycal systems include duplicated, parallel systems with voting, example: Apollo guidence computer. Some system have several independent computers performing calculations, and results are compared and voted by majority. This design allows to decrease the posibility of glitches and errors to cause the crashes. This particular event highlighted the problem we have with the machine driven decision making: the machine runs the algorithm designed by humans TOO WELL: the edge conditions may result in instability. The testing of the edge condition is very important. But it is realy difficult to perform cause the Financial Engeneering systems operates on many varables and symulations used during systems design may not encounter the particular cases.
