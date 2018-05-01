//
//  main.cpp
//  nn1338_hw2_q4
//
//  Created by NomNomNam on 4/25/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that reads from the user two positive integers, and prints the result of when we add, subtract multiply, divide, div and mod them.
 
 Your program should interact with the user exactly as it shows in the following example:
 
 Please enter two positive integers, separated by a space:
 14 4
 14 + 4 = 18
 14 – 4 = 10
 14 * 4 = 56
 14 / 4 = 3.5
 14 div 4 = 3
 14 mod 4 = 2
 
 */

#include <iostream>
using namespace std;

int main() {
    
    int firstInt, secondInt;
    int addTwoInts, subTwoInts, multTwoInts, divTwoInts, moduloTwoInts;
    float divTwoDoubleInts;
    
    cout<<"Please enter two positive integers, separated by a space:"<<endl;
    cin>>firstInt>>secondInt;
    
    addTwoInts = firstInt + secondInt;
    subTwoInts = firstInt - secondInt;
    multTwoInts = firstInt * secondInt;
    
    // Cast type float onto integer
    divTwoDoubleInts = (float) firstInt / secondInt;
    
    divTwoInts = firstInt / secondInt;
    moduloTwoInts = firstInt % secondInt;
    
    cout<<firstInt<<" + "<<secondInt<<" = "<<addTwoInts<<endl;
    cout<<firstInt<<" - "<<secondInt<<" = "<<subTwoInts<<endl;
    cout<<firstInt<<" * "<<secondInt<<" = "<<multTwoInts<<endl;
    cout<<firstInt<<" / "<<secondInt<<" = "<<divTwoDoubleInts<<endl;
    cout<<firstInt<<" div "<<secondInt<<" = "<<divTwoInts<<endl;
    cout<<firstInt<<" mod "<<secondInt<<" = "<<moduloTwoInts<<endl;
    
    return 0;
}
