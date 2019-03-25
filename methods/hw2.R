library (ISLR)
names(Weekly)
summary (Weekly)
cor(Weekly [,1:8])
pairs(Weekly [,1:8])
attach (Weekly)
Weekly
plot(Volume)
# 1.c
glm.fits=glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume , data=Weekly ,family=binomial)
summary (glm.fits)
coef(glm.fits)
glm.fits$terms
glm.pred =predict(glm.fits,type ="response")
contrasts(Direction)
glm.prob=rep ("Down" ,1089)
glm.prob[glm.pred >.5]="Up"
## 
table(glm.prob,Direction )
## 1.d
train =(Year <2009)
Weekly.2009=Weekly[!train,]
Direction.2009= Direction[!train]
glm.fits=glm(Direction~Lag2,data=Weekly,family=binomial,subset=train)
summary (glm.fits)
coef(glm.fits)

glm.probs =predict(glm.fits,Weekly.2009 , type="response")
glm.pred=rep ("Down" ,104)
glm.pred[glm.probs >.5]="Up"
table(glm.pred ,Direction.2009)
mean(glm.pred== Direction.2009)
mean(glm.pred!= Direction.2009)

# 1.e
library (MASS)
lda.fit=lda(Direction~Lag2 ,data=Weekly ,subset =train)
lda.fit
plot(lda.fit)
##
pred.lda= predict(lda.fit, Weekly.2009)
table(pred.lda$class, Direction.2009)

# 1.f
qda.fit=qda(Direction~Lag2 ,data=Weekly ,subset =train)
qda.fit
#
qda.pred =predict (qda.fit ,Weekly.2009)
table(qda.pred$class ,Direction.2009)

# 1.g
library (class)
train.X=  as.matrix(Lag2[train])
test.X=  as.matrix(Lag2[!train])
train.Direction =Direction[train]
set.seed(1)
knn.pred=knn (train.X,test.X,train.Direction ,k=1)
table(knn.pred, Direction.2009)

# Logistic regression with Lag2, Lag1
fit.glm= glm(Direction~Lag2:Lag1, data=Weekly, family = binomial, subset=train)
summary(fit.glm)
probs1= predict(fit.glm, Weekly.2009, type = "response")
pred.glm= rep("Down", length(probs1))
pred.glm[probs > 0.5] = "Up"
table(pred.glm, Direction.2009)
mean(pred.glm == Direction.2009)

# LDA with Lag2 interaction with Lag1
fit.lda2= lda(Direction ~ Lag2:Lag1, data = Weekly, subset = train)
pred.lda2= predict(fit.lda2, Weekly.2009)
mean(pred.lda2$class == Direction.2009)

# QDA with Lag 2 + log(abs(Lag1))
fit.qda2= qda(Direction ~ Lag2 + log(abs(Lag1)), data = Weekly, subset = train)
pred.qda2= predict(fit.qda2, Weekly.2009)
table(pred.qda2$class, Direction.2009)
mean(pred.qda2$class == Direction.2009)


# KNN k =10
pred.knn2= knn(train.X, test.X, train.Direction, k = 10)
table(pred.knn2, Direction.2009)
mean(pred.knn2 == Direction.2009)

# KNN k =100
pred.knn3= knn(train.X, test.X, train.Direction, k = 100)
table(pred.knn3, Direction.2009)

