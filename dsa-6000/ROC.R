n <- 100  # Number of cases in the data set

# Data frame with two columns: score is randomly generated, true.class is initialized to 0
df <- data.frame(score = runif(n), true.class = rep(0,n)) 

# Set the true.class values (0 or 1) according to the score value
# Note that in reality, true.class is known (not artificially generated)
df$true.class <- sapply(df$score, function(x) rbinom(1,1,x))

# Sort by score (high to low)
df <- df[order(-df$score),]
rownames(df) <- NULL  # Reset the row number to 1,2,3,...

# Total # of positive and negative cases in the data set
P = sum(df$true.class == 1)
N = sum(df$true.class == 0)

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

