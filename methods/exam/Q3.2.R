df <- read.csv('airpollution.csv')
names(df)
apply(df,2, mean)
apply(df,2, var)
pca <- prcomp(df, scale=TRUE)
names(pca)
print(pca$center)
print(pca$scale)
print(pca$rotation)
dim(pca$x)
biplot(pca, scale=0)
pr_var <- pca$sdev^2
pve <- pr_var/sum(pr_var)
print(pve)
plot(pve, xlab="Principal Component"
     , ylab="Proportion of Variance Explained "
     , ylim=c(0,1)
     ,type='b')
plot(cumsum(pve), xlab="Principal Component "
     , ylab=" Cumulative Proportion of Variance Explained "
     , ylim=c(0,1)
     , type='b')
