#0. read f1les
airlaines.file <- 'data/stock_market_data-AAL.csv'
rel.file <- 'data/RELIANCE.csv'

df.aal <- read.csv(airlaines.file, colClasses = c('numeric','Date','numeric','numeric','numeric','numeric'))
df.rel <- read.csv(rel.file, colClasses = c('Date','numeric','numeric','numeric','numeric','numeric','numeric'))

library(dplyr)

df.aal <- df.aal %>% select(Date, Close)
# AAL sorted backwards
df.aal <- df.aal[order(df.aal$Date),]
rownames(df.aal) <- NULL
df.rel <- df.rel %>% select(Date,Close)
df.rel <- df.rel[order(df.rel$Date),]
rownames(df.rel) <- NULL

library(ggplot2)
# 1. Plot Close
ggplot(df.aal, aes(df.aal$Date, y = Close, color = variable)) + 
  geom_line(aes(y = df.aal$Close, col = "Close"))

ggplot(df.rel, aes(df.rel$Date, y = Close, color = variable)) + 
  geom_line(aes(y = df.rel$Close, col = "Close"))

#2. ADF tests forp Close
# https://en.wikipedia.org/wiki/Augmented_Dickey%E2%80%93Fuller_test
library(tseries)
# ADF test on Close AAL
print(adf.test(df.aal$Close,alternative = "stationary"))
# ADF test on Close REL
print(adf.test(df.rel$Close,alternative = "stationary"))

#3.
#transform
ar_ret <- function(P) {c(NA, P[2:length(P)]/P[1:(length(P)-1)] -1)}
log_ret <- function(P) {c(NA, log(P[2:length(P)]/P[1:(length(P)-1)]))}
# AAL returns
df.aal$ar_ret <- ar_ret(df.aal$Close)
df.aal$log_ret <- log_ret(df.aal$Close)
df.aal <- na.omit(df.aal)
# REL returns
df.rel$ar_ret <- ar_ret(df.rel$Close)
df.rel$log_ret <- log_ret(df.rel$Close)
df.rel <- na.omit(df.rel)

#4. Plot Returns
ggplot(df.aal, aes(df.aal$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df.aal$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df.aal$log_ret, col = "log_ret"))
#
# Plot Returns
ggplot(df.rel, aes(df.rel$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df.rel$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df.rel$log_ret, col = "log_ret"))
# Zoom - shoe 100 
df100 <- df.aal[99:130,]
ggplot(df100, aes(df100$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df100$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df100$log_ret, col = "log_ret"))


# ACF-PACF of AR of AAL
acf(df.aal$ar_ret)
pacf(df.aal$ar_ret)
# ACF-PACF of LOGR of AAL
acf(df.aal$log_ret)
pacf(df.aal$log_ret)
# ACF PACF of REL
acf(df.rel$ar_ret)
pacf(df.rel$ar_ret)
acf(df.rel$log_ret)
pacf(df.rel$log_ret)
#5. ADF tests on Ret
# ADF test on ariphmetic return
print(adf.test(df.aal$ar_ret, alternative = "stationary"))
# ADF test on log return
print(adf.test(df.aal$log_ret, alternative = "stationary"))
# ADF test on return
print(adf.test(df.rel$ar_ret, alternative = "stationary"))
print(adf.test(df.rel$log_ret, alternative = "stationary"))


library(stats)
library(forecast)
#
aal.ar.autoarima <- auto.arima(df.aal[1:3000,]$ar_ret,
                               max.order=300,
                               trace = TRUE)
aal.ar.autoarima.log <- auto.arima(df.aal[1:3000,]$log_ret,
                               max.order=300,
                               trace = TRUE)

print(aal.ar.autoarima)
print(aal.ar.autoarima.log)

tsdisplay(residuals(aal.ar.autoarima), lag.max=15)
tsdisplay(residuals(aal.ar.autoarima.log), lag.max=15)
print(summary(aal.ar.autoarima))
print(summary(aal.ar.autoarima.log))

test_f <- forecast(aal.ar.autoarima,h=14)
checkresiduals(test_f)#aal.ar.autoarima)
plot(test_f, include= 30,
     ylab = 'Ariphmetic Returns', 
     xlab = 'Day', 
     main = 'Arithmetic Returns: Actual vs Prodicted')
lines(df.aal$ar_ret)

test_f_log <- forecast(aal.ar.autoarima.log,h=14)
checkresiduals(test_f_log)#aal.ar.autoarima)
plot(test_f_log, include= 30,
     ylab = 'Log Returns', 
     xlab = 'Day', 
     main = 'Log Returns: Actual vs Prodicted')
lines(df.aal$log_ret)
#
# Fit REL
rel.ar.autoarima <- auto.arima(df.rel[1:5500,]$ar_ret,
                               stepwise=FALSE,
                               parallel = TRUE, 
                               num.cores = 4,
                               max.order=300)
print(rel.ar.autoarima)
plot(forecast(rel.ar.autoarima,h=10),include = 30)

#AAL Training set
df.aal.train <- head(df.aal,3000)
#AAL Testinng set
df.aal.test <- tail(df.aal,length(df.aal)-3000)

aal.model <- Arima(df.aal.train$ar_ret,order=c(3,0,3))
plot(forecast(aal.model,h=14), include=28)
#lines(df.aal.test$ar_ret)

# Apply fitted model to later data
aal.model2 <- Arima(df.aal.test$ar_ret,model=aal.model)

# Forecast accuracy measures on the log scale.
# in-sample one-step forecasts.
accuracy(aal.model)
# out-of-sample one-step forecasts.
accuracy(aal.model2)
# out-of-sample multi-step forecasts
accuracy(forecast(aal.model,h=14,lambda=NULL),df.aal.test$ar_ret)
