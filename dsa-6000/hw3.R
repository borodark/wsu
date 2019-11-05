Power3=function(x,a){
  rc <- x^a
  return(rc)
}

library(purrr)

PlotPower=function(x, into_power){
  y <- map (x,function(x) Power3(x,into_power))
  plot(x,y)
}

PlotPower(1:10,3)

# Normal Gaussian
ProbabilityDensityFunction <- function(x, μ, σ){
  (sqrt(2*pi)*σ)^-1*exp(-(2*σ^2)^-1*(x-μ))
}

σ <- sqrt(36) # 

# issued a dividend
π_1 <- .8
μ_1 <- 10

# didn't issue a dividend
π_0 <- .2
μ_0 <- 0


# probabilities for issue - 1 no-issue - 0
x <- 4
probablilityOfIssue <- (π_1*ProbabilityDensityFunction(4,μ_1,σ))/(π_1*ProbabilityDensityFunction(4,μ_1,σ) + π_0*ProbabilityDensityFunction(4,μ_0,σ))
probablilityOfNonIssue <- (π_0*ProbabilityDensityFunction(4,μ_0,σ))/(π_1*ProbabilityDensityFunction(4,μ_1,σ) + π_0*ProbabilityDensityFunction(4,μ_0,σ))

print("For X == 4 ")
print("Probablility Of Issue: ")
print(probablilityOfIssue)
print("Probablility Of Non Issue: ")
print(probablilityOfNonIssue)


rd <- c(12,23,43,55,33,88,99)
sd(rd)
t(t(rd))


a <- c(9.6,11.4,9.5,6.8,9.8,13.9)
sd(a)
summary(a)
b <- c(7.5,6.3, 6.1, 7.3)
summary(b)
sd(b)

x <- 8.4
(ldA <- x * 10.167/(sd(a)^2) - 10.167^2/(2*sd(a)^2) + log(.6))
(ldB <- x * 6.80/(sd(a)^2) - 6.80^2/(2*sd(a)^2) + log(.6))
