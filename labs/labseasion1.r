#install.packages()
library (MASS)
library (ISLR)
library(ggplot2)
######################################
# Vector and Matrtix
x <- c(1,3,2,5)
x
y = c(1,4,3,6)
length (x)
length (y)
x+y
x=rnorm (50)
y=x+rnorm (50, mean=50, sd=.1)
cor(x,y)
set.seed (1303)
rnorm (50)
set.seed (3)
y=rnorm (100)
mean(y)
var(y)
sqrt(var(y))
sd(y)

x=matrix (data=c(1,2,3,4) , nrow=2, ncol =2)
x
x=matrix (c(1,2,3,4) ,2,2)
x
matrix (c(1,2,3,4) ,2,2,byrow =TRUE)
sqrt(x)
x^2

# Indexing

A=matrix (1:16 ,4 ,4)
A
A[2,3]
A[c(1,3) ,c(2,4) ]
A[1:3 , 2:4]
A[1:2 ,]
A[ ,1:2]
A[-c(1,3) ,]
dim(A)


# Graphic

x=rnorm (100)
y=rnorm (100)
plot(x,y)
plot(x,y,xlab=" this is the x-axis",ylab=" this is the y-axis", main=" Plot of X vs Y")

# Loading Data

Auto=read.table ("Auto.data")
fix(Auto)
Auto=read.table ("Auto.data", header =T,na.strings ="?")
fix(Auto)
Auto=read.csv ("Auto.csv", header =T,na.strings ="?")
dim(Auto)
Auto=na.omit(Auto)
dim(Auto)
names(Auto)
pairs(Auto)
pairs(~ mpg + displacement + horsepower + weight + acceleration , Auto)
plot(Auto$horsepower ,Auto$mpg)
identify (Auto$horsepower ,Auto$mpg ,Auto$name)
summary (Auto)

# Linear Regression
data("Boston")
fix("Boston")
names(Boston)
lm.fit =lm(medv~lstat ,data=Boston )
attach (Boston )
lm.fit =lm(medv~lstat)
lm.fit
names(lm.fit )
coef(lm.fit)
confint (lm.fit)

predict (lm.fit ,data.frame(lstat=c(5 ,10 ,15, 20) ), interval ="confidence")
plot(lstat, age)
abline (lm.fit)
ggplot(data = Boston, mapping = aes(x = lstat, y = medv)) + geom_point() + geom_smooth(method = "lm")
par(mfrow=c(2,2))
plot(lm.fit)

lm.fit =lm(medv~lstat+age ,data=Boston )
summary (lm.fit)

summary(lm.fit)$r.sq
# Non-linear regession

lm.fit =lm(medv~lstat*age,data=Boston )
lm.fit =lm(medv~.,data=Boston )

lm.fit2=lm(medv~age+I(lstat ^2))
lm.fit =lm(medv~lstat)
anova(lm.fit ,lm.fit2)
lm.fit5=lm(medv~poly(age ,5))
summary (lm.fit5)
summary (lm(medv~log(rm),data=Boston ))

library (car)
vif(lm.fit)
#	Qualitative Predictors
Carseats
fix(Carseats)
names(Carseats)
lm.fit =lm(Sales~.+ Income :Advertising +Price :Age ,data=Carseats )
summary (lm.fit)
attach (Carseats )
contrasts (ShelveLoc)


