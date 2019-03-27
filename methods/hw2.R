library (ISLR)
names(Weekly)
summary (Weekly)
cor(Weekly [,1:8])
pairs(Weekly [,1:8])
attach (Weekly)
plot(Volume)
# 1.c
glm.fits <- glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume , data=Weekly ,family=binomial)
summary(glm.fits)
coef(glm.fits)
glm.fits$terms
glm.pred <- predict(glm.fits,type ="response")
contrasts(Direction)
glm.prob <- rep ("Down" ,1089)
glm.prob[glm.pred >.5] <- "Up"
## 
table(glm.prob,Direction )
## 1.d
train <- (Year <2009)
Weekly.2009 <- Weekly[!train,]
Direction.2009 <- Direction[!train]
glm.fits <- glm(Direction~Lag2,data=Weekly,family=binomial,subset=train)
summary(glm.fits)
coef(glm.fits)

glm.probs <- predict(glm.fits,Weekly.2009 , type="response")
glm.pred <- rep ("Down" ,104)
glm.pred[glm.probs >.5] <- "Up"
table(glm.pred ,Direction.2009)
mean(glm.pred == Direction.2009)
mean(glm.pred!= Direction.2009)

# 1.e
library (MASS)
lda.fit <- lda(Direction~Lag2 ,data=Weekly ,subset =train)
lda.fit
plot(lda.fit)
##
pred.lda <- predict(lda.fit, Weekly.2009)
table(pred.lda$class, Direction.2009)

# 1.f
qda.fit <- qda(Direction~Lag2 ,data=Weekly ,subset =train)
qda.fit
#
qda.pred <- predict (qda.fit ,Weekly.2009)
table(qda.pred$class ,Direction.2009)

# 1.g
library (class)
train.X <-  as.matrix(Lag2[train])
test.X <-  as.matrix(Lag2[!train])
train.Direction <- Direction[train]
set.seed(1)
knn.pred <- knn (train.X,test.X,train.Direction ,k=1)
table(knn.pred, Direction.2009)

# Logistic regression with Lag2, Lag1
fit.glm <- glm(Direction~Lag2:Lag1, data=Weekly, family  <- binomial, subset=train)
summary(fit.glm)
probs1 <- predict(fit.glm, Weekly.2009, type = "response")
pred.glm <- rep("Down", length(probs1))
pred.glm[probs > 0.5]  <- "Up"
table(pred.glm, Direction.2009)
mean(pred.glm == Direction.2009)

# LDA with Lag2 interaction with Lag1
fit.lda2 <- lda(Direction ~ Lag2:Lag1, data = Weekly, subset = train)
pred.lda2 <- predict(fit.lda2, Weekly.2009)
mean(pred.lda2$class == Direction.2009)

# QDA with Lag 2 + log(abs(Lag1))
fit.qda2 <- qda(Direction ~ Lag2 + log(abs(Lag1)), data = Weekly, subset = train)
pred.qda2 <- predict(fit.qda2, Weekly.2009)
table(pred.qda2$class, Direction.2009)
mean(pred.qda2$class == Direction.2009)


# KNN k =10
set.seed(1)
pred.knn2 <- knn(train.X, test.X, train.Direction, k = 10)
table(pred.knn2, Direction.2009)
mean(pred.knn2 == Direction.2009)

# KNN k =100
pred.knn3 <- knn(train.X, test.X, train.Direction, k = 100)
table(pred.knn3, Direction.2009)
mean(pred.knn3 == Direction.2009)

# 2 
library(MASS)
attach(Boston)
#
crim01 <- rep(0, length(crim))
crim01[crim > median(crim)] <- 1
index <- 1:length(crim)
# crim01
Boston <- data.frame(index,subset(Boston, select = -c(crim)), crim01)
Boston.train <- Boston[sample(nrow(Boston), nrow(Boston) * .75 ), ]
Boston.test <- Boston[ !(Boston$index %in% Boston.train$index), ]
crim01.test <- crim01[Boston.test$index]
# crim01.test
dim(Boston.test)
dim(Boston.train)
#
fit.glm <- glm(crim01 ~.-index, data= Boston.train, family= binomial)
summary(fit.glm)
par(mfrow=c(2,2))
plot(fit.glm)
probs <- predict(fit.glm, Boston.test, type = "response")
length(probs)
pred.glm <- rep(0, length(probs))
pred.glm[probs > 0.5] <- 1
table(pred.glm, crim01.test)
length(probs)
#
mean(pred.glm == crim01.test)
mean(pred.glm != crim01.test)
# 
fit.glm2 <- glm(crim01 ~. -index -tax -rm, data = Boston.train, family = binomial)
summary(fit.glm2)
par(mfrow=c(2,2))
plot(fit.glm2)
probs2 <- predict(fit.glm2, Boston.test, type = "response")
pred.glm2 <- rep(0, length(probs2))
pred.glm2[probs2 > 0.5] <- 1
table(pred.glm2, crim01.test)
mean(pred.glm2 == crim01.test)
mean(pred.glm2 != crim01.test)

#
# 2 LDA
library (MASS)
lda.fit <- lda(crim01 ~. -index, data = Boston.train)
lda.fit
plot(lda.fit)
##
pred.lda <- predict(lda.fit,Boston.test)
table(pred.lda$class, crim01.test)
mean(pred.lda$class == crim01.test)
mean(pred.lda$class != crim01.test)

# drop "index" column
train = Boston.train[,-1]
test = Boston.test[,-1]

#2 KNN=1
library (class)
knn.pred1 <- knn(train=train, test=test, cl=train$crim01, k=1)
table(knn.pred1, crim01.test)
mean(knn.pred1 == crim01.test)
mean(knn.pred1 != crim01.test)

#2 KNN=3
knn.pred3 <- knn(train=train, test=test, cl=train$crim01, k=3)
table(knn.pred3, crim01.test)
mean(knn.pred3 == crim01.test)
mean(knn.pred3 != crim01.test)

#2 KNN=7
knn.pred7 <- knn(train=train, test=test, cl=train$crim01, k=7)
summary(knn.pred7)
table(knn.pred7, crim01.test)
mean(knn.pred7 == crim01.test)
mean(knn.pred7 != crim01.test)

#3.a
set.seed(10)
library(ISLR)
library(caret)
library(e1071)
i.Train.o <- createDataPartition(y = OJ$Purchase, p = 800/nrow(OJ), list = FALSE)   
train <- OJ[i.Train.o, ]
test <- OJ[-i.Train.o, ]

#3.b
svm.fit <- svm(Purchase ~. , data = train, cost = 0.01, kernel = 'linear')
summary(svm.fit)
#
train.pred <- predict(svm.fit)
test.pred <- predict(svm.fit, newdata = test)
tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)
tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)
#
#3.d
tune.out <- tune(svm, Purchase ~ ., data = train, kernel = "linear", ranges = list(cost = 10^seq(-2, 1, by = 0.5)))
summary(tune.out)

tune.out$best.model
# 3.e
svm.linear <- svm(Purchase ~ ., kernel = "linear", data = train, cost = tune.out$best.parameter$cost)
train.pred <- predict(svm.linear, train)
test.pred <- predict(svm.linear, newdata = test)

tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)

tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)

# 3.f
# 3.fb
svm.fit <- svm(Purchase ~. , data = train, cost = 0.01, kernel = 'radial')
summary(svm.fit)
# 3.fc
train.pred <- predict(svm.fit)
test.pred <- predict(svm.fit, newdata = test)
tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)
tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)
#
# 3.fd
tune.out <- tune(svm, Purchase ~ ., data = train, kernel = "radial", ranges = list(cost = 10^seq(-2, 1, by = 0.5)))
summary(tune.out)
tune.out$best.model
# 3.fe
svm.radial <- svm(Purchase ~ ., kernel = "radial", data = train, cost = tune.out$best.parameter$cost)
train.pred <- predict(svm.radial, train)
test.pred <- predict(svm.radial, newdata = test)
tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)
tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)

# 3.g
#3.gb
svm.fit <- svm(Purchase ~. , data = train, cost = 0.01, kernel = 'polynomial', degree=2)
summary(svm.fit)
# 3.gc
train.pred <- predict(svm.fit)
test.pred <- predict(svm.fit, newdata = test)
tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)
tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)
#
#3.gd
tune.out <- tune(svm, Purchase ~ ., data = train, kernel = "polynomial",degree=2, ranges = list(cost = 10^seq(-2, 1, by = 0.5)))
summary(tune.out)
tune.out$best.model
# 3.ge
svm.polynomial <- svm(Purchase ~ ., kernel = "polynomial", degree=2, data = train, cost = tune.out$best.parameter$cost)
train.pred <- predict(svm.polynomial, train)
test.pred <- predict(svm.polynomial, newdata = test)
tr_table <- table(Predict = train.pred, Truth = train$Purchase)
tst_table <- table(Predict = test.pred, Truth = test$Purchase)
tr_table
tst_table
#
(tr_table[2,1] +  tr_table[1,2])/sum(tr_table)
#
(tst_table[2,1] +  tst_table[1,2])/sum(tst_table)
