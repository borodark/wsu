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
#
sapply(Boston, mode)
#

lm.fit.full <- lm(medv ~ ., data = Boston)
summary(lm.fit.full)
#Now display the model summary using summary(lm.fit.full) and answewr these questions.
#Q8: How many predictors are used in this model fit?
# 13
#Q9: Which predictors have a significant effect on the response variable at a confidence level of 0.95?
coef(lm.fit.full)
#               Estimate Std. Error t value Pr(>|t|)    
#crim        -1.080e-01  3.286e-02  -3.287 0.001087 ** 
#zn           4.642e-02  1.373e-02   3.382 0.000778 ***
#chas         2.687e+00  8.616e-01   3.118 0.001925 ** 
#nox         -1.777e+01  3.820e+00  -4.651 4.25e-06 ***
#rm           3.810e+00  4.179e-01   9.116  < 2e-16 ***
#dis         -1.476e+00  1.995e-01  -7.398 6.01e-13 ***
#rad          3.060e-01  6.635e-02   4.613 5.07e-06 ***
#tax         -1.233e-02  3.760e-03  -3.280 0.001112 ** 
#ptratio     -9.527e-01  1.308e-01  -7.283 1.31e-12 ***
#black        9.312e-03  2.686e-03   3.467 0.000573 ***
#lstat       -5.248e-01  5.072e-02 -10.347  < 2e-16 ***
#Q10: Does age present a significant effect on medv in this model?
# No  p-value: 0.958229 
 
(VIF_age <- 1/(1-summary(lm(age ~ .-medv, data = Boston))$r.sq)) 
#
library(car)
vif(lm.fit.full)
#
lm.fit.all_but_age <- lm(medv ~ . - age, data = Boston)
# Q11: Compare the Multiple R-squared and Adjusted R-sqaured values between this model and the full model. Comment on the differences. Which model do you think is better?
summary(lm.fit.all_but_age) # Multiple R-squared:  0.7406,	Adjusted R-squared:  0.7343
summary(lm.fit.full) # Multiple R-squared:  0.7406,	Adjusted R-squared:  0.7338 
#
AIC(lm.fit.full) 
# [1] 3027.609
BIC(lm.fit.full)
# [1] 3091.007
AIC(lm.fit.all_but_age)
# [1] 3025.611
BIC(lm.fit.all_but_age)
# [1] 3084.783

