# CIS25 Project 1

This repository contains the source code for CIS25 Project 1.

Unit Price Calculator.  
A program that calculates a product's unit price in another weight unit and currency.  
It prompts users to enter the product's net weight, weight unit, price, currency, target weight unit, and target currency.  
It then fetches the current currency conversion rate from an API[^1] and calculates the unit price in the target weight unit and target currency.

## [Code walk through](https://youtu.be/yvOAlP9YSDo)

## How to compile
### Linux
```
cd Unit-Price-Calculator
mkdir build
g++ -std=c++20 -o build/main *.cpp util/*.cpp
```
### Windows
```
cd Unit-Price-Calculator
mkdir build
cl -EHsc -std:c++20 -W4 -Fe:build/main.exe *.cpp util/*.cpp
```
### MacOS
```
cd Unit-Price-Calculator
mkdir build
clang++ -std=c++20 -o build/main *.cpp util/*.cpp
```

[^1]: Free Currency Exchange Rates API [exchange-api](https://github.com/fawazahmed0/exchange-api).