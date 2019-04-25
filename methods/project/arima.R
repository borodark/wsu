ar_ret <- function(P) {c(NA, P[2:length(P)]/P[1:(length(P)-1)] -1)}
log_ret <- function(P) {c(NA, log(P[2:length(P)]/P[1:(length(P)-1)]))}
airlaines.file <- 'data/stock_market_data-AAL.csv'
rel.file <- 'data/RELIANCE.csv'

df.aal <- read.csv(airlaines.file, colClasses = c('numeric','Date','numeric','numeric','numeric','numeric'))
df.rel <- read.csv(rel.file, colClasses = c('Date','numeric','numeric','numeric','numeric','numeric','numeric'))

library(dplyr)

df.aal <- df.aal %>% select(Date, Close)
# AAL sorted backwards
df.aal <- df.aal[order(df.aal$Date),]

# AAL returns
df.aal$ar_ret <- ar_ret(df.aal$Close)
df.aal$log_ret <- log_ret(df.aal$Close)
df.aal <- na.omit(df.aal)

# REL returns
df.rel <- df.rel %>% select(Date, Close)
df.rel$ar_ret <- ar_ret(df.rel$Close)
df.rel$log_ret <- log_ret(df.rel$Close)
df.rel <- na.omit(df.rel)


library(tseries)
# https://en.wikipedia.org/wiki/Augmented_Dickey%E2%80%93Fuller_test
# ADF test on ariphmetic return
print(adf.test(df.aal$ar_ret))
# ADF test on log return
print(adf.test(df.aal$log_ret))
# ADF test on Close
print(adf.test(df.aal$Close))
library(ggplot2)
# Plot Close
ggplot(df.aal, aes(df.aal$Date, y = Close, color = variable)) + 
  geom_line(aes(y = df.aal$Close, col = "Close"))
# Plot Returns
ggplot(df.aal, aes(df.aal$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df.aal$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df.aal$log_ret, col = "log_ret"))

# ADF test on return
print(adf.test(df.rel$ar_ret, alternative = "stationary"))
print(adf.test(df.rel$log_ret))
# ADF test on Close
print(adf.test(df.rel$Close))
#
# Plot Close
ggplot(df.rel, aes(df.rel$Date, y = Close, color = variable)) + 
  geom_line(aes(y = df.rel$Close, col = "Close"))
# Plot Returns
ggplot(df.rel, aes(df.rel$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df.rel$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df.rel$log_ret, col = "log_ret"))
# Zoom - shoe 100 
df100 <- df.aal[99:200,]
ggplot(df100, aes(df100$Date, y = Returns, color = variable)) + 
  geom_line(aes(y = df100$ar_ret, col = "ar_ret")) +  
  geom_line(aes(y = df100$log_ret, col = "log_ret"))

Acf(df.rel$ar_ret)
Pacf(df.rel$log_ret)

#AAL Training set
df.aal.train <- head(df.aal,3000)
#AAL Testinng set
df.aal.test <- tail(df.aal,length(df.aal)-3000)

library(stats)
aal.arima.tr <- arima(x = df.aal.train$ar_ret, order = c(2,0,2) )

library(forecast)

aal.ar.autoarima <- auto.arima(df.aal.train$ar_ret,
                               xreg = ,
                               max.p = 30, 
                               max.q = 30, 
                               max.d = 3,
                               trace = TRUE)
print(aal.ar.autoarima)

tsdisplay(residuals(aal.ar.autoarima), lag.max=15)
accuracy(aal.ar.autoarima)
print(summary(aal.ar.autoarima))
test_f <- forecast(aal.ar.autoarima,h=5)
checkresiduals(test_f)#aal.ar.autoarima)
plot(test_f)
library(TSPred)
plotarimapred(df.aal, 
              aal.ar.autoarima, 
              xlim=c(3000,3392),
              range.percent = 0.2,
              ylab = 'Returns', 
              xlab = 'Date', 
              main = 'Returns: Actual vs Prodicted')

# Fit REL
rel.ar.autoarima <- auto.arima(df.rel$ar_ret,
                               stepwise=FALSE,
                               parallel = TRUE, 
                               num.cores = 4,
                               max.order=300)
print(rel.ar.autoarima)
plot(forecast(rel.ar.autoarima,h=4))


