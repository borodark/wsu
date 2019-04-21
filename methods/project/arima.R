ar_ret <- function(P) {c(NA, P[2:length(P)]/P[1:(length(P)-1)] -1)}
log_ret <- function(P) {c(NA, log(P[2:length(P)]/P[1:(length(P)-1)]))}
airlaines.file <- 'data/stock_market_data-AAL.csv'
rel.file <- 'data/RELIANCE.csv'
df.aal <- read.csv(airlaines.file, colClasses = c('numeric','Date','numeric','numeric','numeric','numeric'))
df.rel <- read.csv(rel.file, colClasses = c('Date','numeric','numeric','numeric','numeric','numeric','numeric'))
# AAL returns
df.aal$ar_ret <- ar_ret(df.aal$Close)
df.aal$log_ret <- log_ret(df.aal$Close)
# na.omit(df.aal$ret)
library(tseries)
# ADF test on ariphmetic return
print(adf.test(na.omit(df.aal$ret)))
#
print(adf.test(na.omit(df.aal$ret)))
# ADF test on Close
print(adf.test(na.omit(df.aal$Close)))
# ADF test on Open
print(adf.test(na.omit(df.aal$Open)))
# Realiance returns
df.rel$ret <- returns(df.rel$Close)
# na.omit(df.aal$ret)
# ADF test on return
print(adf.test(na.omit(df.rel$ret)))
# ADF test on Close
print(adf.test(na.omit(df.rel$Close)))
# ADF test on Open
print(adf.test(na.omit(df.rel$Open)))
#
library(forecast)

aal.arima
