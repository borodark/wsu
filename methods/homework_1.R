library (ISLR)
Auto=read.table ("Auto.data", header =T,na.strings ="?")
set.seed(1)
names(Auto)
attach(Auto)
pairs(~horsepower+mpg, Auto)
train= sample(392,196)
lm.fit =lm(mpg~horsepower ,data=Auto,subset=train)
mean((mpg- predict(lm.fit, Auto))[-train]^2)
summary(lm.fit)
coef(lm.fit)
lm.fit2 =lm(mpg~poly(horsepower,2) ,data=Auto,subset=train)
mean((mpg- predict(lm.fit2, Auto))[-train]^2)

lm.fit3 =lm(mpg~poly(horsepower,3) ,data=Auto,subset=train)
mean((mpg- predict(lm.fit3, Auto))[-train]^2)
set.seed(2)
train= sample(392,196)

lm.fit =lm(mpg~horsepower ,data=Auto,subset=train)
mean((mpg- predict(lm.fit, Auto))[-train]^2)
summary(lm.fit)
coef(lm.fit)

library(boot)
glm.fit= glm(mpg~horsepower, data=Auto)
coef(lm.fit)
cv.err=cv.glm(Auto,glm.fit)
cv.err$delta

cv.error =rep(0,5)
detach(Auto)

attach(Wage)

fit =lm(wage~poly(age,3) ,data=Wage)
coef(summary(fit))

fit2a =lm(wage~age+I(age^2)++I(age^3)+I(age^4) ,data=Wage)
coef(summary(fit2a))



predict (lm.fit3 ,data.frame(horsepower=c(90,95,98,100) ), interval ="confidence")

ggplot(data = Auto, mapping = aes(x = horsepower, y = mpg)) + geom_point() + geom_smooth(method = "lm")
par(mfrow=c(2,2))
plot(lm.fit)
plot(Auto$horsepower ,Auto$mpg)
abline (lm.fit)
