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
dim(Smarket.2009)
Direction.2009= Direction[!train]
glm.fits=glm(Direction~Lag2,data=Smarket,family=binomial,subset=train)
summary (glm.fits)
coef(glm.fits)
glm.probs =predict(glm.fits,Smarket.2009 , type="response")
glm.pred=rep ("Down" ,104)
glm.pred[glm.probs >.5]="Up"
table(glm.pred ,Direction.2009)
mean(glm.pred== Direction.2009)
mean(glm.pred!= Direction.2009)

# 1.e
library (MASS)
lda.fit=lda(Direction~Lag2 ,data=Smarket ,subset =train)
lda.fit
plot(lda.fit)
lda.pred=predict (lda.fit , Smarket.2009)
names(lda.pred)
lda.pred
sum(lda.pred$posterior [ ,1] >=.5)
sum(lda.pred$posterior [,1]<.5)


confusionmatrix(Direction.2009, lda.pred$class)

# 1.f

qda.fit=qda(Direction~Lag1+Lag2 ,data=Smarket ,subset =train)
qda.fit
qda.class =predict (qda.fit ,Smarket.2005) $class
table(qda.class ,Direction.2005)
mean(qda.class == Direction.2005)
#
library (class)
train.X=cbind(Lag1 ,Lag2)[train ,]
test.X=cbind (Lag1 ,Lag2)[!train ,]
train.Direction =Direction [train]
set.seed (1)
knn.pred=knn (train.X,test.X,train.Direction ,k=1)
table(knn.pred ,Direction.2005)
