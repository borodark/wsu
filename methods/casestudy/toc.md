# Case study: Aproaches and Methods of anslysies of finsncial time serial data.

The application of quantitative methods in finance has greatly increased in recent years because of the data being collected and are available over internet, some data is free for other one have access after paying some fee. Data is being collected for many variables in a number of countries and at a finest timescale available. Computing resources are available in the forms of public cloud: AWS, Google Compute. The statistical packages for analyzing financial data are available for free as open source, for example: R. The availability threshold has lowered givig the possibility of application to a wider audience.
It is possible now to apply analysis and forecast the behaviour of market instruments cause the number of statisstical methods were developed in recent years. We'll review several methods and consider define critera to measure performance of differnt methods.

## Defenitions and components of Time Series
The ability to forecast a temporal sequence of data into the future is critical in many industries: finance, transportation and manufacturing are a few examples.
The time series is a set of data points, measured for a period time, can be defined as a set of vectors x(t),t = 0,1,2,... where t represents the time elapsed [2]. The variable x(t) is treated as a random variable. The measurements taken are arranged in a proper chronological order.
For example sizes and tollerences of parts produced by automated manufacturing equipment. It is important to observe the series to understand if equipment perform well to mitigate the potential of producing deffective parts and wasting raw material.
The array of [Open,High,Low,Close,Volume] combined with _Stock symbol_[IBM,AMZ,...] and a _Time Stamp_ in form of Minute, Day, Week of the year is typical representation of Stock market time series.
A time series containing records of one variable is termed as univariate. If observation  of more than one variable are considered are called the multivariate.
A time series can be continuous or discrete. The continuous time series have observations are measured at every instance of time: amount of fuel burned by engine or speed and direction of the wind at some geo location point is the example of continues time series. The discrete time series contains observations captured or recorded at discrete points of time: Weekly Return, Daily Log Return are examples of discrete time series. It is possible to trnsform continues time series into discrete usin Fourier transform [1].

### Stationarity
A time series is stationary when there is no systematic _Trend_, no _Systematic change in variance_ and no _Irregularity_ is observed, and seasonality does not exist.
A strictly stationary time series is one for which the probabilistic behavior of every collection of values:

**{x<sub>t1</sub>,x<sub>t2</sub>,...,x<sub>tk</sub> }**

is identical to that of the time shifted set. That is,

**{x<sub>t1+h</sub>,x<sub>t2+h</sub>,...,x<sub>tk+h</sub>}**

**Pr{x<sub>t1</sub> ≤ c<sub>1</sub>,...,x<sub>tk</sub> ≤c<sub>k</sub>} = Pr{x<sub>t1+h</sub> ≤c<sub>1</sub>,...,x<sub>tk+h</sub> ≤ c<sub>k</sub>}**

_for all k =1,2,..., all time points t<sub>1</sub>,t<sub>2</sub>,...,t<sub>k</sub>, all numbers c<sub>1</sub>,c<sub>2</sub>,...,c<sub>k</sub>,and alltime shifts h = 0, ±1, ±2, ... ._ 

This definition also also implies that mean function of the series, μ , if exists, at any points _s_ and _t_, is constant for all _s_ and _t_, and hence μ must be constant. 

Most processes in nature appear to be non-stationary so strict stationarity is too strong of a definition, the assessment of strict stationarity from a single data set is not easy[1]. Rather than imposing conditions on all possible distributions of a time series, less strict version is used: conditions imposed only on the first two moments of the series.

The **weakly stationary time series**, x<sub>t</sub> , is a finite variance process such that 
 * the mean value function, **μ<sub>t</sub>**  is constant and does not depend on time _t_
 * the autocovariance function, **γ(_s_, _t_)**, depends on **_s_** and **_t_** only through their difference **|_s_ − _t_|**.

The strong and weak stationarity does not imply each other. A weakly stationary process following normal distribution is strongly stationary. So the concept of stationarity is a mathematical idea constructed to simplify the theoretical and practical development of stochastic processes. To design a proper model, adequate for future forecasting, the underlying time series is expected to be stationary[2].

_Irregular_ variations in a time series are caused by unpredictable influences, that do not repeat in a particular pattern. These variations are caused by incidents like natural disasters, breakdown of equipment, sensor mulfuncions, abrupt changes in business environments like bancruptsies, firm collapses and global events influences the observed process. There is no statistical technique for measuring _Irregular_ fluctuations in a time series.

 
## Finansial Time Series Characteristics
The studies of financial time series mostly involve returns, instead of prices. For some investors, return of an asset is a simplest summary of the investment opportunity. Second, return series are easier to handle than price series because the returns have more attractive statistical properties[4].

### Asset returns

Let _P<sub>t</sub>_ be the _price_ of an asset at time index _t_.

#### One-Period Simple Return

The asset beeing hold for one period from date t − 1 to date t would result in a _simple gross return_
* __1+R<sub>t</sub> = P<sub>t</sub>__  or  __P<sub>t</sub> = P<sub>t-1</sub>(1+R<sub>t</sub>)__

The corresponding one-period _simple net return_ or _simple return_ is
* __R<sub>t</sub> = (P<sub>t</sub>/P<sub>t−1</sub>) - 1 = (P<sub>t</sub> - P<sub>t−1</sub>)/P<sub>t−1</sub>__

The formula is different if market a instrument has to pay dividends or coupon in case of bonds during analysed period.

#### Continuously Compounded Return
The natural logarithm of the simple gross return of an asset is called the continuously compounded return or log return:

* **r<sub>t</sub>** = ln( 1 + **R<sub>t</sub>** ) = ln( **P<sub>t</sub> / P<sub>t−1</sub>**) = **p<sub>t</sub>** − **p<sub>t−1</sub>**

where **p<sub>t</sub>** = ln( **P<sub>t</sub>** ). Continuously compounded returns **r<sub>t</sub>** have an advantage over the simple net returns *R<sub>t</sub>* : _the multiperiod log return is the sum of continuously compounded one-period log returns_. Also according to [3] statistical properties of log returns are more tractable.

## ARIMA models

## Box-Jenkins Methodology for ARIMA models

## SVM application to time series analisys

The theory of Support Vector Machines was develop by applied mathematins from Soviet Union Vapnik, Chervonenkis and others [2]. The Vapnic later worked in Bell Labs []. The SVM differs from other methods besause there are no probabalistic concepts emploied: it feels like typical Computer Sciense take on the problem of classification. The classification method in financial time series analisys can be employed if we consider that problem can be formulated the following way: given the history of financial instrument perdict the direction - will it be up or down. The _Up_ or _Down_ becomes categorical variables and a classification methods can be used.

## Deep learning and neural networks application: RNN and LTSM

Deep learning neural networks characterized by these three relevant capabilities [2]:
* support multiple inputs and outputs
* capable of learning the arbitrary mappings of inputs to outputs
* able to automatically extract patterns in inputs that spans over long sequences

In time series, time isn’t just a metric, but a primary axis. This additional dimension represents both an opportunity and a constraint for time series data because it provides a source of additional information but makes time series problems challenging. 

Neural networks can be useful for time series forecasting problems by eliminating the immediate need for massive feature engineering processes, data scaling procedures, and the need for making the data stationary by differencing

## Measure of performance of the forecasts

There are number of important measures for judging forecast accuracy of the fitted model. Each has some unique properties. Conducting experiments one must consider more than one performance criteria to obtain key error components: amount, magnitude and direction. This will give an alternative opinion on the key components of overall forecast error.
Please refer to [2] for formulas for each measure and let's consider important properties of each measure.

* Mean Forecast Error (MFE)
  * Measure of the average deviation of forecasted values from actual ones
  * when MFE close to 0 one have a good forecast with minimum bias 
* Mean Absolute Error (MAE)
  * Measures the average absolute deviation of forecasted values from original ones, AKA as the Mean Absolute Deviation (MAD)
  * Good forecast should have smallest possible MAE
  * Shows the magnitude of overall error, occurred due to forecasting
* Mean Absolute Percentage Error (MAPE)
  * Represents the percentage of average absolute error occurred  
* Mean Percentage Error (MPE)
  * Shows the percentage of average error occurred
  * Good forecast's MPE should be small
* Mean Squared Error (MSE)
  * Measures an average squared deviation of forecasted values
  * Gives an overall idea about errors
  * Not as intuitive and easily interpretable as the other measures
* Sum of Squared Error (SSE)
  * Measures the total squared deviation of forecasted observations from the actual values
* Signed Mean Squared Error (SMSE)
  * Same as MSE, except that the original sign of error is kept
* Root Mean Squared Error (RMSE)
  * the square root of calculated MSE
* Normalized Mean Squared Error (NMSE)
  * Normalizes the obtained MSE after dividing it by the test variance
  * Balanced error measure effective in judging forecast accuracy of a model
  * Smaller the NMSE value better the forecast
* Theil’s U-statistics (TU-s)
  * Values are between 0 ≤ U≤ 1; U=0 means a perfect fit.
  * For assessing good forecast accuracy, it is desirable that the U-statistic is close to zero.

| Measure/properties                      | MFE | MAE | MAPE | MPE | MSE | SSE | SMSE | RMSE | NMSE | TU-s |
| :--                                     | --  | --  | ---  | --  | --- | --- | ---  | ---  | ---  | ---  |
| shows error direction                   | +   | -   | -    | +   | -   | -   | +    | -    | -    | -    |
| penalize extreme errors                 | -   | -   | -    | -   | +   | +   | +    | +    | +    | -    |
| positive and negative errors cancel out | +   | -   | -    | +   | -   | -   | +    | -    | -    | -    |
| depends on the scale of measurement     | +   | +   | +    | +   | +   | +   | +    | +    | +    | +    |
| affected by data transformation         | +   | +   | +    | +   | +   | +   | +    | +    | +    | +    |

Any time series analysis have to use more then one performance verification to make sure selected model is adequate.

## Applied analysis with R: libraries available
### ARIMA
### SVM
### ANN

## The plan for Log return analisys of daily time series in the Course Project

## Literature

[1] Robert H. Shumway David S. Stoffer, Time Series Analysis and Its Applications With R Examples, Fourth Edition
[2] Ratnadip Adhikari R. K. Agrawal, An Introductory Study on Time Series Modeling and Forecasting
[3] Analysis of Financial Time Series, Financial Econometrics, RUEY S. TSAY University of Chicago
[4] Tsay, Ruey S., An introduction to analysis of financial data with R/Ruey S. Tsay. p. cm. Includes index. ISBN 978-0-470-89081-3
[5] An Empirical Evaluation of Generic Convolutional and Recurrent Networks for Sequence Modeling, Shaojie Bai, J. Zico Kolter, Vladlen Koltun
[6] Temporal Convolutional Networks: A Unified Approach to Action Segmentation by Colin Lea Rene ́ Vidal Austin Reiter Gregory D. Hager, Johns Hopkins University
[7] A comparison of performance of several artificial intelligence methods for forecasting monthly discharge time series by Wen-Chuan Wang, Kwok-Wing Chau, Chun-Tian Cheng, Lin Qiu, Journal of Hydrology, Vol. 374, No. 3-4, 2009, pp 294–306
