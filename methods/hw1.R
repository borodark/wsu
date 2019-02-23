library (ISLR)
Auto=read.table ("Auto.data", header =T,na.strings ="?")
names(Auto)
attach(Auto)
pairs(~ mpg + horsepower, Auto)

lm.fit =lm(mpg~horsepower ,data=Auto)
summary(lm.fit)

predict (lm.fit, level = 0.95, data.frame(horsepower=98 ), interval ="confidence")

predict(lm.fit, level = 0.95, data.frame(horsepower = 98), interval = "prediction")


plot(lm.fit)
plot(horsepower ,mpg)
abline (lm.fit)


