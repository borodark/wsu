library(MASS) 
lm.fit <- lm(medv ~ lstat + age, data = Boston)
summary(Boston)
#Q1
sum((Boston$medv - median(Boston$medv))^2)
#Fit medv (median house value) as a linear function of lstat (percentage of lower status of the population) and age (proportion of units built prior to 1940).
lm.fit <- lm(medv ~ lstat + age, data = Boston)
summary(lm.fit)
#From the model summary, answer these questions:
# Q2: What is the Residual Sum of Squares (RSS) of this fit?
anova(lm.fit)
deviance(lm.fit)
sum(resid(lm.fit)^2)
#
# Q3: How much proportion of the variance in medv is accounted for by this fit?
summary(lm.fit)
# Multiple R-squared:  0.5513,	Adjusted R-squared:  0.5495 
#
# Q4: Overall, is there a relationship between the response variable medv and the predictors lstat and age? How do you make such a conclusion?
# not much the age but lstat: p-value: < 2.2e-16

# Q5: Is there a relationship between medv and each of the predictors? How do you tell?
plot(Boston$lstat,Boston$medv)
cor(Boston$lstat,Boston$medv)
medv <- scale(Boston$medv, center=TRUE, scale=TRUE)
lstat <- scale(Boston$lstat, center=TRUE, scale=TRUE)
plot(lstat,medv)
cor(lstat,medv)
#
plot(Boston$medv, Boston$age)
cor(Boston$medv, Boston$age)

# Q6: What is the estimated standard deviation of the irreducible error in the model . 
summary(lm.fit)$sigma
#
# Q7: How do you interpret the coefficient estimate on age, i.e., the value 0.0345, in the model context?
# each +1 on age causes increace in  medv of 0.0345 

sapply(Boston, mode)
