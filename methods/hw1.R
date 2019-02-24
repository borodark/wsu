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


head(Carseats)
contrasts(US)
str(data.frame(Price, Urban, US))
