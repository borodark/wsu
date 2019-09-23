college <- read.csv("College.csv")
fix(college)
rownames(college)=college[,1]
college <- college[, -1]
head(college[, 1:5])
#
summary(college)
#
pairs(college[, 1:10])