setwd("~/projects/secret/wsu/wsu/methods")
library (ISLR)
Auto=read.table ("Auto.data", header =T,na.strings ="?")
names(Auto)
attach(Auto)
pairs(~ mpg + horsepower, Auto)

lm.fit =lm(mpg~horsepower ,data=Auto)
summary(lm.fit)

predict (lm.fit, level = 0.95, data.frame(horsepower=98 ), interval ="confidence")

predict(lm.fit, level = 0.95, data.frame(horsepower = 98), interval = "prediction")

#plot(lm.fit)

plot(horsepower ,mpg, col="blue")
abline (lm.fit, col="green")
#### Q2
data(Carseats)
attach(Carseats)
fit <- lm(Sales ~ Price + Urban + US, data = Carseats)
summary(fit)
fit

head(Carseats)
contrasts(US)
str(data.frame(Price, Urban, US))


## Q3
x = rnorm(100)
Yn = rnorm(100)
summary(x)
summary(Yn)

y = 3 + 2 * x - 3*x^2 + 0.3 * x^3 + Yn
require(leaps)
df <- data.frame(y, x)
ggplot(data = df, mapping = aes(x = x, y = y)) + geom_point() + geom_smooth(method = 'loess')

fit <- regsubsets(y ~ poly(x, 10), data = df, nvmax = 10)
fit_summary <- summary(fit)
fit_summary

plot(fit_summary$cp, xlab = str_c("Best # is ",which.min(fit_summary$cp)), ylab = "C_p", type = "l")
points(which.min(fit_summary$cp), fit_summary$cp[which.min(fit_summary$cp)], col = "green", cex = 2, pch = 20)

plot(fit_summary$bic, xlab = str_c("Best # is ", which.min(fit_summary$bic)) , ylab = "BIC", type = "l")
points(which.min(fit_summary$bic), fit_summary$bic[which.min(fit_summary$bic)], col = "green", cex = 2, pch = 20)

plot(fit_summary$adjr2, xlab = str_c("Best # is ", which.max(fit_summary$adjr2)), ylab = "Adjusted R^2", type = "l")
points(which.max(fit_summary$adjr2), fit_summary$adjr2[which.max(fit_summary$adjr2)], col = "green", cex = 2, pch = 20)

fit_fw <- regsubsets(y ~ poly(x, 10), data = df, nvmax = 10, method = "forward")
fit_fw_summary <- summary(fit_fw)
fit_fw_summary

par(mfrow=c(2,2))
plot(fit_fw_summary$cp, xlab = str_c("Using Forward Best # is ",which.min(fit_fw_summary$cp)), ylab = "C_p", type = "l")
points(which.min(fit_fw_summary$cp), fit_fw_summary$cp[which.min(fit_fw_summary$cp)], col = "green", cex = 2, pch = 20)

plot(fit_fw_summary$bic, xlab = str_c("Using Forward Best # is ", which.min(fit_fw_summary$bic)) , ylab = "BIC", type = "l")
points(which.min(fit_fw_summary$bic), fit_fw_summary$bic[which.min(fit_fw_summary$bic)], col = "green", cex = 2, pch = 20)

plot(fit_fw_summary$adjr2, xlab = str_c("Using Forward Best # is ", which.max(fit_fw_summary$adjr2)), ylab = "Adjusted R^2", type = "l")
points(which.max(fit_fw_summary$adjr2), fit_fw_summary$adjr2[which.max(fit_fw_summary$adjr2)], col = "green", cex = 2, pch = 20)

fit_bw <- regsubsets(y ~ poly(x, 10), data = df, nvmax = 10, method = "backward")
fit_bw_summary <- summary(fit_bw)
fit_bw_summary
par(mfrow=c(2,2))
plot(fit_bw_summary$cp, xlab = str_c("Using Backward Best # is ",which.min(fit_bw_summary$cp)), ylab = "C_p", type = "l")
points(which.min(fit_bw_summary$cp), fit_bw_summary$cp[which.min(fit_bw_summary$cp)], col = "green", cex = 2, pch = 20)

plot(fit_bw_summary$bic, xlab = str_c("Using Backward Best # is ", which.min(fit_bw_summary$bic)) , ylab = "BIC", type = "l")
points(which.min(fit_bw_summary$bic), fit_bw_summary$bic[which.min(fit_bw_summary$bic)], col = "green", cex = 2, pch = 20)

plot(fit_bw_summary$adjr2, xlab = str_c("Using Backward Best # is ", which.max(fit_bw_summary$adjr2)), ylab = "Adjusted R^2", type = "l")
points(which.max(fit_bw_summary$adjr2), fit_bw_summary$adjr2[which.max(fit_bw_summary$adjr2)], col = "green", cex = 2, pch = 20)


## Q4 
library(glmnet)
