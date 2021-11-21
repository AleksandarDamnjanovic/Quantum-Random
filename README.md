# Quatnum Random

## Basic information
Here you can find simple Python, R, C and Java  libraries for the purpose of producing radnom numbers from the quatum source. Organization providing source infromation is ANU QRNG through their API. If you use this library on the daily basis or for commercial purpose, I am encouraging you to donate to this people for ther work. Those guys and girls gave tremendous contribution to humanity and moder world by giving this informations for free.

[ANU QRNG](https://qrng.anu.edu.au/) website

[Donation page](https://engage.anu.edu.au/giving/give-now?id=bc08b83a-e103-4038-b394-8d07347084d2)

## Why Quantum Random
Every programming language(at least that I know of) contains feature for generating random numbers. Though, those numbers are not random in real meaning of the word. Random numbers that you can generate through C, Java, Pyton... are generated using speciffic algorithm. In other word, in this way generated numbers are calculated, what makes them not random, but rather, random from human perspective.

Only way to get reall random numbers using modern day technology is from quantum source. From web site of `ANU QRNG` you can find out more, how phisics behind all this works.

## How to use
+ **With Python** you have to instantiate object `QuantumRand`. In the class contructor, firs time is called function `next` that returns random integer. 

    + `getRand` call to get random integer. `getRand` have two optional paramethers `min` for minimal value and `max` for maximal values that should be returned.  
    + `getFloat` to get random decimal value in between 0 and 1. `getFloat` have only `decimal` paramether to format return value with exact number of decimal places.
    + `next` to generate new random value from the same object.

+ **With R**
    + `getRand` with paramethers `minv` for minimal value and `maxv` for maximal value, that returns random integer value. With R those paramether are mandatory.
    + `getFloat` returns random value in between 0 and 1 with paramether `decimal` to describe how many decimal places should be in return value.
    
    Every time you call `getRand` or `getFloat` new random value is generated.

+ **With C** first you have to call function `QuantumRand_next` to generate random value. Then you can use this long value for your purposes or to call some of specialized functions. 
    + `QuantumRand_next_min` have paramether `min` that allows you to set minimun for returning value. 
    + `QuantumRand_next_max` have paramether `max` that allows you to set maximum for returning value. 
    + `QuantumRand_next_min_max` have both `min` and `max` paramethers.
    + `QuantumRand_get_float` function returns float value in between 0 and 1.
    + `QuantumRand_next` to generate new random value.

    In Makefile, there are example of how you can compile shared object from the code from  QuantumRand.h but I believe that the best course of action would be just to include this header file in new object and to compile it with it.
    QuantumRand.h depends on **libcurl** and **libjson-c** libraries.

+ **With Java** same as with Python, first you will have to instantiate object `QuantumRand`. At the same time you will generate first random value for that object to work with.
    + `next` will create new random value and return it.
    + `getLong` will return present random value for that object.
    + `getLong(min, max)` is overloaded `getLong` function that allows you to determine minimal and maximal random value.
    + `getFloat` will return double in between 0 and 1.