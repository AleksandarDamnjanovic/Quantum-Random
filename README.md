# Quatnum Random

## Basic information
Here you can find simple Python and R  libraries for the purpose of producing radnom numbers from the quatum source. Organization providing source infromation is ANU QRNG through their API. If you use this library on the daily basis or for commercial purpose, I am encouraging you to donate to this people for ther work. Those guys and girls gave tremendous contribution to humanity and moder world by giving this informations for free.

[ANU QRNG](https://qrng.anu.edu.au/) website

[Donation page](https://engage.anu.edu.au/giving/give-now?id=bc08b83a-e103-4038-b394-8d07347084d2)

## Why Quantum Random
Every programming language(at least that I know of) contains feature for generating random numbers. Though, those numbers are not random in real meaning of the word. Random numbers that you can generate through C, Java, Pyton... are generated using speciffic algorithm. In other word, in this way generated numbers are calculated, what makes them not random, but rather, random from human perspective.

Only way to get reall random numbers using modern day technology is from quantum source. From web site of `ANU QRNG` you can find out more, how phisics behind all this works.

## How to use
+ With Python you have to instantiate object `QuantumRand`. In the class contructor, firs time is called function `next` that returns random integer. Than you can call functions `getRand` to get random integer or `getFloat` to get random decimal value in between 0 and 1. Function `getRand` have two optional paramethers `min` for minimal value and `max` for maximal values that should be returned. Function `getFloat` have only `decimal` paramether to format return value with exact number of decimal places. If you want new random value from the same object, you will have to call function `next`.

+ With R, there is function `getRand` with paramethers `minv` for minimal value and `maxv` for maximal value, that returns random integer value. With R those paramether are mandatory. Function `getRand` returns random value in between 0 and 1 with paramether `decimal` to describe how many decimal places should be in return value. Every time you call `getRand` or `getFloat` new random value is generated.