x <- matrix(c(1.5,3.2,5.4,8.5))
y <- c(1,1,-1,-1)
train <- data.frame(x=x)
test <- data.frame(x = matrix(c(6.2)))
library (class)
knn(train=train ,test =test, cl=as.factor(y), k=3)



