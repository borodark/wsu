setwd("~/projects/secret/wsu/wsu/dsa-6000")
ad <- read.table(file="Advertising.csv", head=T, sep=",")
ad[,1] <- NULL
head(ad)
scatter.smooth(x=ad$TV,y=ad$sales, main="Sales ~ TV")
boxplot(ad$TV)
hist(ad$TV, breaks = 30, main = "Histogram: TV", xlab = "TV", col="red")
plot(density(ad$TV), main = "Density Plot: TV")
polygon(density(ad$TV), col="red")
cor(ad$sales, ad$TV)

# sales ~ TV

mod1 <- lm(sales ~ TV, data = ad)
summary(mod1)
(mod1.coef <-coef(mod1))
mod1.coef["TV"]
mod1.coef["(Intercept)"]
# plot the model fit
pdf("lm-sales-TV.pdf")
plot(ad$TV, ad$sales, main = "sales ~ TV", xlab = "TV", ylab = "sales", col='blue', pch=20)
abline(mod1, lwd=3)
dev.off()
## training and prediction
set.seed(2019)
trainIndex <- sample(1:nrow(ad),0.7 *nrow(ad))
mod2 <- lm(sales ~ TV, data = ad, subset = trainIndex)
summary(mod2)
# Std. Error is more on mod2, cause perhaps less data in the training set now
pred2 <- predict(mod2, newdata = ad[-trainIndex,])
(testMSE <- mean((pred2 - ad[-trainIndex, 'sales'])^2))
(testMAPE <- mean(abs(pred2 - ad[-trainIndex, 'sales'])))
#
# plot the prediction
# 
plot(ad[-trainIndex, c('TV','sales')], col='red', pch="+", main = "Test Data")
abline(mod2, lwd=2)
newx <- seq(min(ad[-trainIndex, 'TV']), max(ad[-trainIndex, 'TV']), length.out = 100)

# C.I.
pred2.CI <- predict(mod2, newdata = data.frame(TV=newx), interval = 'confidence')
plot(ad[-trainIndex,c('TV','sales')], type='n', main= 'Regression Line with CI')
polygon(c(rev(newx), newx), c(rev(pred2.CI[, 'upr']), pred2.CI[,'lwr']),col = 'grey80',border = NA)
abline(mod2, lwd=2)
points(ad[-trainIndex,c('TV','sales')], col='red', pch='+')
legend("bottomright", legend=c("Test Data","Model"),col=c("red","black"), pch=c("+",NA), lwd = c(0,3))

# P.I.
pred2.PI <- predict(mod2, newdata = data.frame(TV=newx), interval = 'prediction')
plot(ad[-trainIndex,c('TV','sales')], type='n', main= 'Regression Line with PI')
polygon(c(rev(newx), newx), c(rev(pred2.PI[, 'upr']), pred2.PI[,'lwr']),col = 'grey80',border = NA)
abline(mod2, lwd=2)
points(ad[-trainIndex,c('TV','sales')], col='red', pch='+')
# add trainig data points
legend("bottomright", legend=c("Training Data","Test Data","Model"),col=c("blue","red","black"), pch=c("*","+",NA), lwd = c(0,0,3))
points(ad[trainIndex,c('TV','sales')], col='blue', pch='*')

#
mod3 <- lm(sales~TV+radio+newspaper , data = ad, subset = trainIndex)
summary(mod3)
pred3 <- predict(mod3, newdata = ad[-trainIndex,])
(testMSE <- mean((pred3 - ad[-trainIndex, 'sales'])^2))
(testMAPE <- mean(abs(pred3 - ad[-trainIndex, 'sales'])))
#