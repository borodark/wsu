setwd("~/projects/secret/wsu/wsu/dsa-6000")
ad <- read.table(file="Advertising.csv", head=T, sep=",")
ad[,1] <- NULL
scatter.smooth(x=ad$TV,y=ad$sales, main="Sales ~ TV")
boxplot(ad$TV)
hist(ad$TV, breaks = 30, main = "Histogram: TV", xlab = "TV", col="red")
plot(density(ad$TV), main = "Density Plot: TV")
polygon(density(ad$TV), col="red")
cor(ad$sales, ad$TV)

#

mod1 <- lm(sales ~ TV, data = ad)
summary(mod1)
(mod1.coef <-coef(mod1))
mod1.coef["TV"]
mod1.coef["(Intercept)"]
# plot the model fit
plot(ad$TV, ad$sales, main = "sales ~ TV", xlab = "TV", ylab = "sales", col='blue', pch=20)
abline(mod1, lwd=3)

## training and prediction
set.seed(2019)
trainIndex <- sample(1:nrow(ad),0.7 *nrow(ad))
mod2 <- lm(sales ~ TV, data = ad, subset = trainIndex)
summary(mod2)
