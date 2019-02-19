# Time Series Analysis for Log Returns

The project is intend to analyze log return of several market instruments. The main goal explore several kinds of financial times series by adopting a few techniques such as parameter estimation, spectral analysis. After aquiring datasets and transforming to obtain the log return for daily time series we study several market instruments: indexes, currencies. The example of data aquired mostly from https://finance.yahoo.com/: 

* FOREX/DX20000$D.CSV      OK
* FOREX/QE#0000$D.CSV      OK
* FOREX/QE%0000$D.CSV      OK
* FOREX/QE_0000$D.CSV      OK
* FOREX/QE}0000$D.CSV      OK
* FOREX/QE00000$D.CSV      OK
* FOREX/QE20000$D.CSV      OK
* FOREX/QE90000$D.CSV      OK
* FOREX/QF40000$D.CSV      OK
* FOREX/USA0000$D.CSV      OK
* INDEXES/COMP0000$D.CSV   OK
* INDEXES/DJIA0000$D.CSV   OK
* INDEXES/DJTA0000$D.CSV   OK
* INDEXES/DJU2-ID.CSV      OK
* INDEXES/DJU3-ID.CSV      OK
* INDEXES/DJUA0000$D.CSV   OK
* INDEXES/FDX0000$D.CSV    OK
* INDEXES/FFI0000$D.CSV    OK
* INDEXES/RUT-ID.CSV       OK
* INDEXES/SPX-ID.CSV       OK
* INDEXES/SSI0000$D.CSV    OK
* RATES/FVX-ID.CSV         OK
* RATES/IRX-ID.CSV         OK
* RATES/MM10000$D.CSV      OK
* RATES/TNX-ID.CSV         OK
* RATES/TYX-ID.CSV         OK
* STOCKS/AMZN.CSV          OK
* STOCKS/CVX.CSV           OK
* STOCKS/GE.CSV            OK
* STOCKS/WFC.CSV           OK
* STOCKS/XOM.CSV           OK

We assess time series frequency parameters and detect trend and cycles using bandpass filtering. We analize ACF to recommend the model parameters for ARIMA. We research the series for seasonality and explore applicability of SARIMA if series exhibits this behaviour. We assess and compare model accuracies. Moving to Vector ARMA Models we try asses the efford to model several time series jointly to find co-integration.

## Literature

* An Introduction to Statistical Learning with Applications in R by Gareth James, Daniela Witten, Trevor Hastie, Robert Tibshirani
* Time Series Analysis and Its Applications With R Examples by Robert H. Shumway, David S. Stoffer
* Analysis of Financial Time Series Financial Econometrics by RUEY S. TSAY University of Chicago
* [Time series Forecasting — ARIMA models](https://towardsdatascience.com/time-series-forecasting-arima-models-7f221e9eee06)
* [Introduction To Time Series Forecasting](https://www.datascience.com/blog/introduction-to-forecasting-with-arima-in-r-learn-data-science-tutorials)

## Datasets

https://finance.yahoo.com/


## Students
* Ali Milhem	
* Igor Ostaptchenko
