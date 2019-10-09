raw <-  read.csv('flightDelays.csv')
summary(raw)
fl <- raw[complete.cases(raw),]
summary(fl)
# count of differnt airline
table <- table(fl[,'UniqueCarrier'])
prop.table(table)

# cnseled by airkine
(a <-table(fl[,c('Canceled','UniqueCarrier')]))
par(mar=c(4,4,4,4))
barplot(a, beside = T)
pp <- prop.table(a)
barplot(pp, beside = T)

(b <-table(fl[,c('Canceled','Month')]))
barplot(b)

#
# split to to train/test
trainset <- sample(1:nrow(fl), 3995)
validset <- setdiff(1:nrow(fl),trainset)
head(validset)
head(trainset)

m1 <- glm(Canceled ~ ., data = fl, family = binomial, subset = trainset)
pred <- predict(m1, newdata = fl[validset,],type = 'response')
head(pred)
df <- data.frame(score = pred, true.class = fl[validset, 'Canceled'])
head(df)
tail(df)

# Sort by score (high to low)
df <- df[order(-df$score),]
rownames(df) <- NULL  # Reset the row number to 1,2,3,...
# df
# Total # of positive and negative cases in the data set
P = sum(df$true.class == 1)
N = sum(df$true.class == 0)
n = length(validset)

# Vectors to hold the coordinates of points on the ROC curve
TPR = c(0,vector(mode="numeric", length=n))
FPR = c(0,vector(mode="numeric", length=n))
# Calculate the coordinates from one point to the next
for(k in 1:n){
  if(df[k,"true.class"] == 1){
    TPR[k+1] = TPR[k] + 1/P
    FPR[k+1] = FPR[k]
  } else{
    TPR[k+1] = TPR[k]
    FPR[k+1] = FPR[k] + 1/N
  }
}

# Color scheme: Positive case in red, negative case in blue
color = c("black","blue","red")

# Plot the ROC curve
plot(FPR, TPR, main=paste0("ROC curve"," (n = ", n, ")"), pch=16, col=color[(2+c(-1,df$true.class))], cex.lab = 1.5, cex.axis = 1.5, cex.main = 1.5)
lines(FPR,TPR)


fl$Month <- as.factor(fl$Month)
head(fl$Month)
str(fl)

m2 <- glm(Canceled ~ ., data = fl, family = binomial, subset = trainset)
pred2 <-predict(m2, newdata = fl[validset,],type = 'response')
df <- data.frame(score = pred2, true.class = fl[validset, 'Canceled'])
# Sort by score (high to low)
df <- df[order(-df$score),]
rownames(df) <- NULL  # Reset the row number to 1,2,3,...
# df
# Total # of positive and negative cases in the data set
P = sum(df$true.class == 1)
N = sum(df$true.class == 0)
n = length(validset)

# Vectors to hold the coordinates of points on the ROC curve
TPR = c(0,vector(mode="numeric", length=n))
FPR = c(0,vector(mode="numeric", length=n))
# Calculate the coordinates from one point to the next
for(k in 1:n){
  if(df[k,"true.class"] == 1){
    TPR[k+1] = TPR[k] + 1/P
    FPR[k+1] = FPR[k]
  } else{
    TPR[k+1] = TPR[k]
    FPR[k+1] = FPR[k] + 1/N
  }
}

# Color scheme: Positive case in red, negative case in blue
color = c("green","pink","yellow")

# Plot the ROC curve
points(FPR, TPR, main=paste0("ROC curve"," (n = ", n, ")"), pch=16, col=color[(2+c(-1,df$true.class))], cex.lab = 1.5, cex.axis = 1.5, cex.main = 1.5)
lines(FPR,TPR)


fl$Month <- as.factor(fl$Month)
head(fl$Month)
str(fl)

