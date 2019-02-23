library (ISLR)
library (leaps)
fix(Hitters )
names(Hitters)
dim(Hitters)
sum(is.na(Hitters$Salary))
Hitters =na.omit(Hitters )

#Best Subset Selection

regfit.full=regsubsets(Salary~.,Hitters )
summary (regfit.full)
regfit.full=regsubsets (Salary~.,data=Hitters ,nvmax =19)
reg.summary =summary (regfit.full)
names(reg.summary)
reg.summary$rsq
plot(reg.summary$rss ,xlab=" Number of Variables ",ylab=" RSS",
     type="l")
plot(reg.summary$adjr2 ,xlab =" Number of Variables ",
       ylab=" Adjusted RSq",type="l")
which.max (reg.summary$adjr2)
points (11, reg.summary$adjr2[11], col ="red",cex =2, pch =15)

par(mfrow =c(2,2))
plot(regfit.full ,scale ="r2")
plot(regfit.full ,scale ="adjr2")
plot(regfit.full ,scale ="Cp")
plot(regfit.full ,scale ="bic")
#####################

#Forward and Backward Stepwise Selection


regfit.fwd=regsubsets (Salary~.,data=Hitters ,nvmax =19, method ="forward")
summary (regfit.fwd )
regfit.bwd=regsubsets (Salary~.,data=Hitters ,nvmax =19, method ="backward")
summary (regfit.bwd )

coef(regfit.full ,7)
coef(regfit.fwd ,7)
coef(regfit.bwd ,7)
#####################
# Ridge Regressoin

library (glmnet )
x=model.matrix (Salary~.,Hitters )[,-1]
y=Hitters$Salary

grid =10^ seq (10,-2,length =100)
ridge.mod =glmnet (x,y,alpha=0, lambda =grid)
ridge.mod$lambda [50]
coef(ridge.mod)[,50]
predict (ridge.mod ,s=50, type ="coefficients")[1:20 ,]

set.seed (1)
train=sample(1: nrow(x), nrow(x)/2)
test=(- train )
y.test=y[test]
ridge.mod =glmnet(x[train,],y[train],alpha =0,lambda =grid,thresh =1e-12)
ridge.pred=predict (ridge.mod ,s=4, newx=x[test,])
mean(( ridge.pred -y.test)^2)

set.seed (1)
cv.out =cv.glmnet (x[train ,],y[train],alpha =0)
plot(cv.out)
bestlam =cv.out$lambda.min
bestlam
ridge.pred=predict (ridge.mod ,s=bestlam ,newx=x[test ,])
mean(( ridge.pred -y.test)^2)
#####################

# Lasso

lasso.mod =glmnet(x[train ,],y[train],alpha =1,lambda =grid)
plot(lasso.mod)

set.seed (1)
cv.out =cv.glmnet (x[train ,],y[train],alpha =1)
plot(cv.out)
bestlam =cv.out$lambda.min
lasso.pred=predict (lasso.mod ,s=bestlam ,newx=x[test,])
mean(( lasso.pred-y.test)^2)

out=glmnet (x,y,alpha =1, lambda =grid)
lasso.coef=predict (out ,type ="coefficients",s=bestlam )[1:20 ,]
lasso.coef
#####################


#Principal Components Regression

library (pls)
set.seed (1)
pcr.fit=pcr(Salary~., data=Hitters ,scale=TRUE , validation ="CV")
summary (pcr.fit)
validationplot(pcr.fit,val.type="MSEP")
pcr.pred=predict (pcr.fit ,x[test ,], ncomp =7)
mean((pcr.pred -y.test)^2)
######################################











dev.off()
