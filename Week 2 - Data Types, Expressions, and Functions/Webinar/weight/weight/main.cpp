//
//  main.cpp
//  weight
//
//  Created by NomNomNam on 4/22/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

const int OUNCES_TO_POUNDS = 16;

int main() {
    
    int item1Pounds, item1Ounces, item2Pounds, item2Ounces;
    int poundRes, totPounds, poundsCarry, ouncesRem;
    
    // Asking and taking in user input
    cout<<"Please enter the weight of the two items"<<endl;
    cout<<"For each item, give its weight in pounds and ounces, ";
    cout<<"separated by a space:"<<endl;
    
    // Save user input in properly named variables
    cout<<"Item #1: ";
    cin>>item1Pounds>>item1Ounces;
    cout<<"Item #2: ";
    cin>>item2Pounds>>item2Ounces;
    
    // There is 16 ounces in 1 pound. Taking the modulo 16 from adding the two items' ounces together
    // will result in finding the remaining ounces
    ouncesRem = (item1Ounces + item2Ounces) % OUNCES_TO_POUNDS;
    
    // When adding ounces together exceeds multiple of 16 will result in pounds being carried over
    poundsCarry = (item1Ounces + item2Ounces) / OUNCES_TO_POUNDS;
    
    // The total amount in pounds is the result of adding the items' two pounds together and the carry over pound
    // from adding the ounces together
    totPounds = item1Pounds + item2Pounds + poundsCarry;
    
    // Print out result to user
    cout<<"Total = "<<totPounds<<" lbs and "<<ouncesRem<<" oz."<<endl;
    
    return 0;
}
