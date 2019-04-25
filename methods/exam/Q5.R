library(e1071)
library(ggplot2)
x <- matrix(c(1,2,4,5,4,3,5,6), ncol = 2)
y <- c(1,1,-1,-1)
dat <- data.frame(x=x, y=as.factor(y))

# Plot data
ggplot(data = dat, aes(x = x.1, y = x.2, color = y, shape = y)) + 
  geom_point(size = 2) +
  scale_color_manual(values=c("#000000", "#FF0000")) +
  theme(legend.position = "none")

svmfit <- svm(y~., data = dat, kernel = "linear", scale = FALSE)
summary(svmfit)
dat[svmfit$index,]
plot(svmfit, dat)

