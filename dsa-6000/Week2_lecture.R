ad <- read.table(file="clipboard", header=T)
head(ad)
ad_train <- ad[1:100,]
head(ad_train)
ad_test <- ad[101:200,]
m1 <- lm(sales ~ TV + radio + newspaper, data=ad_train)
coef(m1)
head(ad_train)
ad_train$fitted <- fitted(m1)
head(ad_train)
mean((ad_train$sales - ad_train$fitted)^2)
ad_test$pred <- predict(m1, newdata = ad_test[,c("TV","radio","newspaper")])
head(ad_test)
mean((ad_test$sales - ad_test$pred)^2)
