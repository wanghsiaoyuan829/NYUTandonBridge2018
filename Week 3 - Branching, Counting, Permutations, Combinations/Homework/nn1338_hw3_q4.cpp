//
//  main.cpp
//  nn1338_hw3_q4
//
//  Created by NomNomNam on 5/3/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Define the following constants:
 const int FLOOR_ROUND = 1;
 const int CEILING_ROUND = 2;
 const int ROUND = 3;
 
 Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a Real number:
 4.78
 Choose your rounding method:
 1. Floor round
 2. Ceiling round
 3. Round to the nearest whole number
 2
 5
 
 Implementation requirement: Use a switch statement.

*/

#include <iostream>
#include <cmath>
using namespace std;

// Switch cases
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    
    double realNum;
    int roundingMethod;
    int roundedNum;
    
    // Store user input
    cout<<"Please enter a Real number:"<<endl;
    cin>>realNum;
    
    // Gives user options for rounding methods
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    
    cin>>roundingMethod;
    
    // Switch based on user inputs (1, 2, or 3)
    switch (roundingMethod) {
        case FLOOR_ROUND:
            roundedNum = floor(realNum);
            cout<<roundedNum<<endl;
            break;
        case CEILING_ROUND:
            roundedNum = ceil(realNum);
            cout<<roundedNum<<endl;
            break;
        case ROUND:
            roundedNum = round(realNum);
            cout<<roundedNum<<endl;
            break;
        // If the user enters any inputs besides 1, 2, or 3
        default:
            cout<<"Invalid input. Please choose your rounding method again (1, 2 or 3)"<<endl;
            break;
    }
    
    return 0;
}
