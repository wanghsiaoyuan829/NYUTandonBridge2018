//
//  main.cpp
//  nn1338_hw2_q1
//
//  Created by NomNomNam on 4/25/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that asks the user to enter a number of quarters, dimes, nickels and
 pennies and then outputs the monetary value of the coins in the format of dollars and
 remaining cents.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter number of coins:
 # of quarters: 13
 # of dimes: 4
 # of nickels: 11
 # of pennies: 17
 The total is 4 dollars and 37 cents
 
*/

#include <iostream>
using namespace std;

const int CENTS_TO_DOLLAR = 100;
const int VALUE_OF_A_QUARTER = 25;
const int VALUE_OF_A_DIME = 10;
const int VALUE_OF_A_NICKEL = 5;

int main() {
    
    int numOfQuarters, numOfDimes, numOfNickles, numOfPennies; // Store user input
    int amountInQuarters, amountInDimes, amountInNickles, amountInPennies; // Convert cents into relative amount
    int finalDollarAmount, centsLeftover, finalAmountInCents; // Final amount in cents and dollars
    
    cout<<"Please enter number of coins:"<<endl;
    
    // Store user input
    cout<<"# of quarters: ";
    cin>>numOfQuarters;
    
    cout<<"# of dimes: ";
    cin>>numOfDimes;
    
    cout<<"# of nickles: ";
    cin>>numOfNickles;
    
    cout<<"# of pennies: ";
    cin>>numOfPennies;
    
    // Convert cents into relative amount
    amountInQuarters = numOfQuarters * VALUE_OF_A_QUARTER;
    amountInDimes = numOfDimes * VALUE_OF_A_DIME;
    amountInNickles = numOfNickles * VALUE_OF_A_NICKEL;
    amountInPennies = numOfPennies;
    
    // Add all converted amount in cents to get the final amount in cents
    finalAmountInCents = amountInQuarters + amountInDimes + amountInNickles + amountInPennies;
    
    // 100 cents are in 1 dollar and any remainder amount of cents will get stored in centsLeftOver
    centsLeftover = finalAmountInCents % CENTS_TO_DOLLAR;
    
    // 100 cents are in 1 dollar and the divisible amount gets stored in final dollar amount
    finalDollarAmount = finalAmountInCents / CENTS_TO_DOLLAR;
    
    cout<<"The total is "<<finalDollarAmount<<" dollars and "<<centsLeftover<<" cents"<<endl;
    
    return 0;
}
