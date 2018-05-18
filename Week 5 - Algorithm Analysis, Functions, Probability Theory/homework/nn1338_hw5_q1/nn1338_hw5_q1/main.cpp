//
//  main.cpp
//  nn1338_hw5_q1
//
//  Created by NomNomNam on 5/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 The Fibonacci numbers sequence, Fn, is defined as follows:
     F0 is 1, F1 is 1,and Fn = Fn-1 +Fn-2   for n = 2,3,4,...
 In other words, each number is the sum of the previous two numbers. The first 10 numbers in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
 
 Note: Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number
 1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
 sequence.
 2. Write a program that prompts the user to enter a positive integer num, and then
 prints the num’s elements in the Fibonacci sequence.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a positive integer: 7
 13
 
*/

#include <iostream>
using namespace std;

int main() {
    
    int num, fibonacci;
    
    cout<<"Please enter a positive integer: ";
    cin>>num;
    
    cout<<fibonacci;
    
    return 0;
}
