library(ISLR)
head(Auto)
dim(Auto)
getwd()
write.csv(file="Auto.csv", Auto)

# Open the csv in Excel and see what it looks like

write.csv(file="Auto.csv", Auto, row.names = F)

# Open the csv in Excel and notice that the row names are gone
# In Excel, manually delete some cell values to create some missing values in the data table, and save as Auto_with_missing_values.csv

AutoM <- read.csv(file="Auto_with_missing_values.csv", header = T, na.strings = "")
dim(is.na(AutoM))
sum(is.na(AutoM))
is.na(AutoM[,'mpg'])
sum(is.na(AutoM[,'mpg']))
good_rows <- complete.cases(AutoM)
na_rows <- !good_rows
head(good_rows,20)
sum(good_rows)
sum(na_rows)
bad_data <- AutoM[na_rows,]
good_data <- AutoM[good_rows,]
good_data1 <- na.omit(AutoM)

plot(good_data1$cylinders, good_data1$mpg)

