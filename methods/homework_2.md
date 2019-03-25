# Home Work 2

##(Question #10 from chapter 4)

This question should be answered using the Weekly data set, which is part of the ISLR package. This data is similar in nature to the Smarket data from this chapter’s lab, except that it contains 1089 weekly returns for 21 years, from the beginning of 1990 to the end of 2010.
```R
> library (ISLR)
> names(Weekly)
[1] "Year"      "Lag1"      "Lag2"      "Lag3"      "Lag4"      "Lag5"      "Volume"    "Today"     "Direction"

```
### (a) Produce some numerical and graphical summaries of the Weekly data. Do there appear to be any patterns?
```R
> summary (Weekly)
      Year           Lag1               Lag2               Lag3               Lag4               Lag5         
 Min.   :1990   Min.   :-18.1950   Min.   :-18.1950   Min.   :-18.1950   Min.   :-18.1950   Min.   :-18.1950  
 1st Qu.:1995   1st Qu.: -1.1540   1st Qu.: -1.1540   1st Qu.: -1.1580   1st Qu.: -1.1580   1st Qu.: -1.1660  
 Median :2000   Median :  0.2410   Median :  0.2410   Median :  0.2410   Median :  0.2380   Median :  0.2340  
 Mean   :2000   Mean   :  0.1506   Mean   :  0.1511   Mean   :  0.1472   Mean   :  0.1458   Mean   :  0.1399  
 3rd Qu.:2005   3rd Qu.:  1.4050   3rd Qu.:  1.4090   3rd Qu.:  1.4090   3rd Qu.:  1.4090   3rd Qu.:  1.4050  
 Max.   :2010   Max.   : 12.0260   Max.   : 12.0260   Max.   : 12.0260   Max.   : 12.0260   Max.   : 12.0260  
     Volume            Today          Direction 
 Min.   :0.08747   Min.   :-18.1950   Down:484  
 1st Qu.:0.33202   1st Qu.: -1.1540   Up  :605  
 Median :1.00268   Median :  0.2410             
 Mean   :1.57462   Mean   :  0.1499             
 3rd Qu.:2.05373   3rd Qu.:  1.4050             
 Max.   :9.32821   Max.   : 12.0260             
 ```
 
 Draw the correlation matrix

```R
pairs(Weekly [,1:8])
```

![pairs(Weekly [,1:8])](Rplot2-1.svg)

```R
> plot(Volume)
```

![plot(Volume)](Rplot14.svg)

Volume corelates to the week number. Other relations are not so clear.


### (b) Use the full data set to perform a logistic regression with Direction as the response and the five lag variables plus Volume as predictors. Use the summary function to print the results. Do any of the predictors appear to be statistically significant? If so, which ones?

```R
> glm.fits=glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume , data=Weekly ,family=binomial)
> summary (glm.fits)

Call:
glm(formula = Direction ~ Lag1 + Lag2 + Lag3 + Lag4 + Lag5 + 
    Volume, family = binomial, data = Weekly)

Deviance Residuals: 
    Min       1Q   Median       3Q      Max  
-1.6949  -1.2565   0.9913   1.0849   1.4579  

Coefficients:
            Estimate Std. Error z value Pr(>|z|)   
(Intercept)  0.26686    0.08593   3.106   0.0019 **
Lag1        -0.04127    0.02641  -1.563   0.1181   
__Lag2         0.05844    0.02686   2.175   0.0296 *__
Lag3        -0.01606    0.02666  -0.602   0.5469   
Lag4        -0.02779    0.02646  -1.050   0.2937   
Lag5        -0.01447    0.02638  -0.549   0.5833   
Volume      -0.02274    0.03690  -0.616   0.5377   
---
Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for binomial family taken to be 1)

    Null deviance: 1496.2  on 1088  degrees of freedom
Residual deviance: 1486.4  on 1082  degrees of freedom
AIC: 1500.4

Number of Fisher Scoring iterations: 4

> coef(glm.fits)
(Intercept)        Lag1        Lag2        Lag3        Lag4        Lag5 
 0.26686414 -0.04126894  0.05844168 -0.01606114 -0.02779021 -0.01447206 
     Volume 
-0.02274153 

```

**The `Lag2` appears to be the predictor that contribute the most.**

### (c) Compute the confusion matrix and overall fraction of correct predictions. Explain what the confusion matrix is telling you about the types of mistakes made by logistic regression.

```R
> glm.pred =predict(glm.fits,type ="response")
> contrasts(Direction)
     Up
Down  0
Up    1
> glm.prob=rep ("Down" ,1089)
> glm.prob[glm.pred >.5]="Up"
> ## 
> table(glm.prob,Direction )
        Direction
glm.prob Down  Up
    Down   54  48
    Up    430 557
>
```
Interpretation:
```
| Direction |                |                 |      |
| glm.prob  | Down           | Up              |      |
| Down      | True Down=  54 | False Down=  48 |  102 |
| Up        | False Up=  430 | True Up=    557 |  987 |
| totals    | 484            | 605             | 1089 |
```

#### Logistical regression results interpretation

* Accuracy: Overall, how often is the classifier correct?
(True Down +True Up)/total = (54+557)/1089 = 0.56
__The ~56% of time the classifier able to accuratly predict.__

* Misclassification Rate: Overall, how often is it wrong?
(Fase Down + False Up)/total = (430+48)/1089 = 0.44
__Error Rate is ~44%. It is also (1 - Accuracy)__

* True Positive Rate: When it's actually __Up__, how often does it predict __Up__?
True Down/actual Down = 557/987 = 0.56
__It is 56%. This value is also known as "Sensitivity" or "Recall"__

* False Positive Rate: When it's actually __Down__, how often does it predict __Up__?
FP/actual  = 48/102 = 0.47
__It is 47%__

* True Negative Rate (also known as "Specificity"): When it's actually __Down__, how often does it predict __Down__?
TN/actual no = 54/102 = 0.53
__It is 53%. Also it is (1 -  False Positive Rate)__

* Precision: When it predicts __Up__, how often is it correct?
TP/predicted __Up__ = 557/605 = ~0.92

* Prevalence: How often does the __Up__ condition actually occur in our sample?
actual Up/total Up = 987/1089 = ~0.906


### (d) Now fit the logistic regression model using a training data period from 1990 to 2008, with Lag2 as the only predictor. Compute the confusion matrix and the overall fraction of correct predictions for the held out data (that is, the data from 2009 and 2010).

```
> ## 1.d
> train =(Year <2009)
> Weekly.2009=Weekly[!train,]
> Weekly.2009=Weekly[!train,]
> Direction.2009= Direction[!train]
> glm.fits=glm(Direction~Lag2,data=Weekly,family=binomial,subset=train)
> summary (glm.fits)

Call:
glm(formula = Direction ~ Lag2, family = binomial, data = Weekly, 
    subset = train)

Deviance Residuals: 
   Min      1Q  Median      3Q     Max  
-1.536  -1.264   1.021   1.091   1.368  

Coefficients:
            Estimate Std. Error z value Pr(>|z|)   
(Intercept)  0.20326    0.06428   3.162  0.00157 **
Lag2         0.05810    0.02870   2.024  0.04298 * 
---
Signif. codes:  
0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for binomial family taken to be 1)

    Null deviance: 1354.7  on 984  degrees of freedom
Residual deviance: 1350.5  on 983  degrees of freedom
AIC: 1354.5

Number of Fisher Scoring iterations: 4
```

#### Predict on 2009 - 2010 and print confusion matrix

```
> glm.probs =predict(glm.fits,Weekly.2009 , type="response")
> glm.pred=rep ("Down" ,104)
> glm.pred[glm.probs >.5]="Up"
> table(glm.pred ,Direction.2009)
        Direction.2009
glm.pred Down Up
    Down    9  5
    Up     34 56
> mean(glm.pred== Direction.2009)
[1] 0.625
> mean(glm.pred!= Direction.2009)
[1] 0.375
> 
```

##### Interpretation
* Accuracy: Overall, how often is the classifier correct?
(True Down +True Up)/total = (9+56)/104 = 0.625
__The 62.2% of time the classifier able to accuratly predict.__

* Misclassification Rate: Overall, how often is it wrong?
(False Down + False Up)/total = (5+34)/104 = 0.375
__Error Rate is 37.5%.__

* For weeks when the market trend is up-wards, the model is right ~91.80% of the time (56/(56+5))
* For weeks when the market goes down, the model is correct only ~20.93% of the time (9/(9+34))


### (e) Repeat (d) using LDA.
```
> # 1.e
> library (MASS)
> lda.fit=lda(Direction~Lag2 ,data=Weekly ,subset =train)
> lda.fit
Call:
lda(Direction ~ Lag2, data = Weekly, subset = train)

Prior probabilities of groups:
     Down        Up 
0.4477157 0.5522843 

Group means:
            Lag2
Down -0.03568254
Up    0.26036581

Coefficients of linear discriminants:
           LD1
Lag2 0.4414162
```

LDA fit 
![plot(lda.fit)](Rplot15.svg) 

####  Predict on 2009 - 2010 and print confusion matrix

```R
> pred.lda= predict(lda.fit, Weekly.2009)
> table(pred.lda$class, Direction.2009)
      Direction.2009
       Down Up
  Down    9  5
  Up     34 56
  
```
##### Interpretation

*  These results are __THE SAME__ as  _[Logistic Regression](#7)_ model which is not surpising

### (f) Repeat (d) using QDA.
```
> # 1.f
> qda.fit=qda(Direction~Lag2 ,data=Weekly ,subset =train)
> qda.fit
Call:
qda(Direction ~ Lag2, data = Weekly, subset = train)

Prior probabilities of groups:
     Down        Up 
0.4477157 0.5522843 

Group means:
            Lag2
Down -0.03568254
Up    0.26036581
```
####  Predict on 2009 - 2010 and print confusion matrix
```
> qda.pred =predict (qda.fit ,Weekly.2009)
> table(qda.pred$class ,Direction.2009)
      Direction.2009
       Down Up
  Down    0  0
  Up     43 61
```
##### Interpretation

* Accuracy: Overall, how often is the classifier correct?
(True Down +True Up)/total = 61/104 = ~0.5865
__The 58.65% of time the classifier able to accuratly predict.__

* Misclassification Rate: Overall, how often is it wrong?
(Fase Down + False Up)/total = (43+0)/104 = %41.346
__Error Rate is %41.346__

* For weeks when the market trend is up-wards, the model is right 100% of the time (61/(61+0))
* For weeks when the market goes down, the model is __never__ correct: 0/(0+43)



### (g) Repeat (d) using KNN with K = 1.

```R
> # 1.g
> library (class)
> train.X=  as.matrix(Lag2[train])
> test.X=  as.matrix(Lag2[!train])
> train.Direction =Direction[train]
> set.seed(1)
> knn.pred=knn (train.X,test.X,train.Direction ,k=1)
> table(knn.pred, Direction.2009)
        Direction.2009
knn.pred Down Up
    Down   21 30
    Up     22 31
    
```

##### Interpretation

* Accuracy: (True Down +True Up)/total = (21+31)/104 = 0.5
__The 50% of time the classifier able to accuratly predict.__

* Misclassification Rate: Overall, how often is it wrong?
(Fase Down + False Up)/total = (30+22)/104 = %50
__Error Rate is %50__

* For weeks when the market trend is __up__-wards, the model is right __~%50.81967__ of the time: (31/(61))
* For weeks when the market goes __down__, the model is __~%48.8372__ correct: 21/(21+22)


### (h) Which of these methods appears to provide the best results on this data?

The Logistical Regression and LDA are the best with the same Accuracy and Errors, followed by QDA and KNN with K=1
```
|----------------|----------|----------|
| Method         | Accuracy | Error    |
|----------------|----------|----------|
| LDA/Logistical | %62.2    | %37.5    |
| QDA            | %58.65~  | %41.346~ |
| KNN            | %50      | %50      |
|----------------|----------|----------|

```

### (i) Experiment with different combinations of predictors, including possible transformations and interactions, for each of the methods. Report the variables, method, and associated confusion matrix that appears to provide the best results on the held out data. Note that you should also experiment with values for K in the KNN classifier.

#### Logistical regression with combinations of Lag2 and Lag1 => Accuracy: %58.65385

```R
> # Logistic regression with Lag2, Lag1
> fit.glm= glm(Direction~Lag2:Lag1, data=Weekly, family = binomial, subset=train)
> summary(fit.glm)

Call:
glm(formula = Direction ~ Lag2:Lag1, family = binomial, data = Weekly, 
    subset = train)

Deviance Residuals: 
   Min      1Q  Median      3Q     Max  
-1.368  -1.269   1.077   1.089   1.353  

Coefficients:
            Estimate Std. Error z value Pr(>|z|)    
(Intercept)  0.21333    0.06421   3.322 0.000893 ***
Lag2:Lag1    0.00717    0.00697   1.029 0.303649    
---
Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for binomial family taken to be 1)

    Null deviance: 1354.7  on 984  degrees of freedom
Residual deviance: 1353.6  on 983  degrees of freedom
AIC: 1357.6

Number of Fisher Scoring iterations: 4

> probs1= predict(fit.glm, Weekly.2009, type = "response")
> pred.glm= rep("Down", length(probs1))
> pred.glm[probs > 0.5] = "Up"
> table(pred.glm, Direction.2009)
        Direction.2009
pred.glm Down Up
    Down    1  1
    Up     42 60
    
> mean(pred.glm == Direction.2009)
[1] 0.5865385
```



#### LDA with Lag2 interaction with Lag1 => Accuracy: %57.69231

```
> fit.lda2= lda(Direction ~ Lag2:Lag1, data = Weekly, subset = train)
> pred.lda2= predict(fit.lda2, Weekly.2009)
> mean(pred.lda2$class == Direction.2009)

[1] 0.5769231
```

#### QDA: Lag 2+log(abs(Lag1)) => Accuracy: %56.73077
```
> fit.qda2= qda(Direction ~ Lag2 + log(abs(Lag1)), data = Weekly, subset = train)
> pred.qda2= predict(fit.qda2, Weekly.2009)
> table(pred.qda2$class, Direction.2009)
      Direction.2009
       Down Up
  Down    3  5
  Up     40 56
> mean(pred.qda2$class == Direction.2009)
[1] 0.5673077
```

#### KNN k =10 => Accuracy: %54.80769

```R
> # KNN k =10
> set.seed(1)
> pred.knn2= knn(train.X, test.X, train.Direction, k = 10)
> table(pred.knn2, Direction.2009)
         Direction.2009
pred.knn2 Down Up
     Down   17 20
     Up     26 41
> mean(pred.knn2 == Direction.2009)
[1] 0.5480769
```

#### KNN k =100 => Accuracy: %55.76923

```R
> # KNN k =100
> pred.knn3= knn(train.X, test.X, train.Direction, k = 100)
> table(pred.knn3, Direction.2009)
         Direction.2009
pred.knn3 Down Up
     Down    9 12
     Up     34 49
> mean(pred.knn3 == Direction.2009)
[1] 0.5576923

```




### Summary for methods
```
|--------------------------------|-----------|
| Method                         | Accuracy  |
| Logistic Regression: Lag2:Lag1 | %58.65385 |
| LDA: Lag2:Lag1                 | %57.69231 |
| QDA: Lag 2+log(abs(Lag1))      | %56.73077 |
| KNN k =100                     | %55.76923 |
| KNN k =10                      | %54.80769 |
|--------------------------------|-----------|

```
