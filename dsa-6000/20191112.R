# Define normalization function 
normalize <- function(x){
    normalized_x <- (x - min(x))/(max(x) - min(x))
    return (normalized_x) 
}

College <- read.csv(file = "College.csv", header = T) 
dim(College)
# Remove the bad data point(s)
College <- College[which(College$Grad.Rate <= 100), ] 
dim(College)
# Extract some attributes of interest and do normalization
x <- as.data.frame(lapply(College[, c('PhD','Outstate','Grad.Rate')], normalize)) 
head(x)
# Perform k-means clustering on x, try 3 clusters first 
kmx <- kmeans(x, 3)
# Display the cluster centroids 
kmx$centers
# Visualize
library(rgl) # install it by install.packages("rgl") 
plot3d(x, col = kmx$cluster)
library(scatterplot3d) # install first 
scatterplot3d(x, color = kmx$cluster)
# Suppose we want to examine the joint distribution of Acceptance Rate and Graduation Rate # Define Acceptance Rate
College$AcceptRate <- College$Accept/College$Apps
# Extract the two attributes
x2 <- College[, c('AcceptRate','Grad.Rate')]
head(x2)
# AcceptRate is between 0 and 1 and Grad.Rate is between 0 and 100
# If we don't do normalization before clustering:
kmx2 <- kmeans(x2, 3)
plot(x2, col = kmx2$cluster)
# We can see that the cluster partition is clear cut along the dominant attribute
# Now let's scale the Grad.Rate to the interval [0,1]
x2n <- data.frame(AcceptRate = College$AcceptRate, GradRate = College$Grad.Rate/100)                    
head(x2n)
kmx2n <- kmeans(x2n, 3)
plot(x2n, col = kmx2n$cluster)
kmx2n$centers # print out the
# Add the cluster centroids to points(kmx2n$centers, pch=20, cex=2, col=c(1,2,3))
# Try the pam (partitioning around medoids) method
library(cluster)
x3n <- data.frame(AcceptRate = College$AcceptRate, GradRate = College$Grad.Rate/100, row.names = College$X)
pamx3n <- pam(x3n,3)
# medoids are the "representative members" of the clusters
# they are the observation within a cluster for which the sum of the distances
# between it and all the other members of the cluster is a minimum
pamx3n$medoids
plot(x3n, col = pamx3n$clustering)
points(pamx3n$medoids, pch=20, cex=1.5, col=c(1,2,3))
# Exercise 1: try 4 clusters, and print out the medoids.

pamx4n <- pam(x3n,4)
pamx4n$medoids
plot(x3n, col = pamx4n$clustering)
points(pamx4n$medoids, pch=20, cex=1.5, col=c(1,2,3))
