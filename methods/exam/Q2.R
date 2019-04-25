library (class)
x <- as.matrix(c(1.5,3.2,5.4,6.2,8.5))
y <- as.matrix(c(1,1,-1,-1,-1))
train <- data.frame(x=x)
test <- data.frame(x = matrix(c(3.84,3.85)))
knn3 <-knn(train=train ,test =test, cl=as.factor(y), k=3, prob=TRUE)
print(knn3)
attributes(knn3)
table(knn3,test)
summary(knn3)


