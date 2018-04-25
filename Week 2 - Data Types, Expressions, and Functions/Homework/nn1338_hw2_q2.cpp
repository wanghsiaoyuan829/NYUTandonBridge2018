//
//  main.cpp
//  nn1338_hw2_q2
//
//  Created by NomNomNam on 4/25/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that asks the user to enter an amount of money in the format of dollars and
 remaining cents. The program should calculate and print the minimum number of coins
 (quarters, dimes, nickels and pennies) that are equivalent to the given amount.
 
 Hint: In order to find the minimum number of coins, first find the maximum number of
 quarters that fit in the given amount of money, then find the maximum number of dimes
 that fit in the remaining amount, and so on.
 
 Your program should interact with the user exactly as it shows in the following example:
 
 Please enter your amount in the format of dollars and cents separated by a space:
 4 37
 4 dollars and 37 cents are:
 17 quarters, 1 dimes, 0 nickels and 2 pennies
 
 */

#include <iostream>
using namespace std;

int main() {
    
    int dollarInputAmount, centInputAmount;
    int dollarToCent, totalCentAmount;
    int minQuarterAmount, minDimeAmount, minNickelAmount, minPennyAmount;
    
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollarInputAmount>>centInputAmount;
    
    cout<<dollarInputAmount<<" dollars and "<<centInputAmount<<" cents are:"<<endl;
    
    // Convert dollar(s) to cent(s)
    dollarToCent = dollarInputAmount * 100;
    
    // Get total cent amount to be able to calculate minimum coin amounts
    totalCentAmount = dollarToCent + centInputAmount;
    
    // To get minimum coin amounts, start off with the biggest coin (quarter) and divide total cent amount
    minQuarterAmount = totalCentAmount / 25;
    
    // After dividing it by the quarter, based on sequential flow, the next biggest coin is the dime
    // Take the amount leftover  and divide by 10 to find how many times go into the remaining amount
    minDimeAmount = (totalCentAmount - minQuarterAmount * 25) / 10;
    
    // Continue this idea with nickels and pennies
    minNickelAmount = (totalCentAmount - minQuarterAmount * 25 - minDimeAmount * 10) / 5;
    
    minPennyAmount = (totalCentAmount - minQuarterAmount * 25 - minDimeAmount * 10 - minNickelAmount * 5) / 1;
    
    // Print-out of the coins
    cout<<minQuarterAmount<<" quarters, "<<minDimeAmount<<" dimes, "<<minNickelAmount<<" nickels";
    cout<<" and "<<minPennyAmount<<" pennies"<<endl;
    
    return 0;
}
