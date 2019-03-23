library (ISLR)
names(Weekly)
summary (Weekly)
?Weekly
cor(Weekly [,1:8])
pairs(Weekly [,1:8])
attach (Weekly )
plot(Volume)
glm.fits=glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume , data=Weekly ,family=binomial)
summary (glm.fits)
coef(glm.fits)
glm.probs =predict (glm.fits,type ="response")
glm.probs [1:10]
contrasts(Direction)
glm.pred=rep ("Down " ,1250)
glm.pred[glm.probs >.5]=" Up"
table(glm.pred ,Direction )
train =(Year <2005)
Smarket.2005=Smarket[!train,]
dim(Smarket.2005)
Direction.2005= Direction[!train]
glm.fits=glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume,data=Smarket,family=binomial,subset=train)
glm.probs =predict(glm.fits,Smarket.2005 , type="response")
glm.pred=rep ("Down" ,252)
glm.pred[glm.probs >.5]=" Up"
table(glm.pred ,Direction.2005)
mean(glm.pred== Direction.2005)
mean(glm.pred!= Direction.2005)

glm.fits=glm(Direction~Lag1+Lag2+Volume , data=Smarket ,family=binomial)
summary (glm.fits)
coef(glm.fits)
glm.probs =predict (glm.fits,Smarket.2005 , type="response")
glm.pred=rep("Down" ,252)
glm.pred[glm.probs >.5]="Up"
table(glm.pred ,Direction.2005)
mean(glm.pred== Direction.2005)

#####

library (MASS)
lda.fit=lda(Direction~Lag1+Lag2 ,data=Smarket ,subset =train)
lda.fit
plot(lda.fit)
lda.pred=predict (lda.fit , Smarket.2005)
names(lda.pred)
sum(lda.pred$posterior [ ,1] >=.5)
sum(lda.pred$posterior [,1]<.5)
sum(lda.pred$posterior [,1]>.9)
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
