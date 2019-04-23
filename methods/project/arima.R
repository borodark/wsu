ar_ret <- function(P) {c(NA, P[2:length(P)]/P[1:(length(P)-1)] -1)}
log_ret <- function(P) {c(NA, log(P[2:length(P)]/P[1:(length(P)-1)]))}
airlaines.file <- 'data/stock_market_data-AAL.csv'
rel.file <- 'data/RELIANCE.csv'

df._aal <- read.csv(airlaines.file, colClasses = c('numeric','Date','numeric','numeric','numeric','numeric'))
df.rel <- read.csv(rel.file, colClasses = c('Date','numeric','numeric','numeric','numeric','numeric','numeric'))
# AAL sorted backwards
library(dplyr)


df._aal <- df._aal %>% select(Date, Close)
df.aal <- df._aal[order(df._aal$Date),]

# AAL returns
df.aal$ar_ret <- ar_ret(df.aal$Close)
df.aal$log_ret <- log_ret(df.aal$Close)
# na.omit(df.aal$ret)
library(tseries)
# https://en.wikipedia.org/wiki/Augmented_Dickey%E2%80%93Fuller_test
# ADF test on ariphmetic return
print(adf.test(na.omit(df.aal$ar_ret)))
# ADF test on log return
print(adf.test(na.omit(df.aal$log_ret)))
# ADF test on Close
print(adf.test(na.omit(df.aal$Close)))
# Realiance returns
df.rel$ar_ret <- ar_ret(df.rel$Close)
df.rel$log_ret <- log_ret(df.rel$Close)
# na.omit(df.aal$ret)
# ADF test on return
print(adf.test(na.omit(df.rel$ar_ret)))
print(adf.test(na.omit(df.rel$log_ret)))
# ADF test on Close
print(adf.test(na.omit(df.rel$Close)))
#
library(stats)
aal.arima <- arima(x = df.aal$ar_ret, order = c(2,0,2) )
print(coef(aal.arima))
print(summary(aal.arima))
library(forecast)

aal.ar.autoarima <- auto.arima(df.aal$ar_ret,max.p = 30, max.q = 30, max.d = 3, trace = TRUE)
print(aal.ar.autoarima)

rel.ar.autoarima <- auto.arima(df.rel$ar_ret,max.order=30, trace = TRUE)
print(rel.ar.autoarima)

