//
//  main.cpp
//  nn1338_hw5_q4
//
//  Created by NomNomNam on 5/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 a. Implement a function:
 void printDivisors(int num)
 This function is given a positive integer num, and prints all of num’s divisors in an ascending
 order, separated by a space.
 For Example, if we call printDivisors(100), the expected output is:
 1 2 4 5 10 20 25 50 100
 
 Implementation requirement: Pay attention to the running time of your function. An
 efficient implementation would run in 0(num^1/2).
 
 b. Use the function above when implementing a program that reads from the user a positive
 integer (≥2), and prints all it’s divisors.
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a positive integer >= 2: 100
 1 2 4 5 10 20 25 50 100

 */

#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num) {
    
    int divisor;
    
//    0(num/2)
    for (int i = 1; i <= num/2; i++) {
        if(num % i == 0)
            cout<<i<<" ";
    }
    cout<<num;
    cout<<endl;
    
//    0(sqrt(num)
    // for (int i = 1; i <= sqrt(num); i++) {
    //     if(num % i == 0) {
    //         divisor = num / i;
    //         cout<<i<<" ";
    //         cout<<divisor<<" ";
    //     }
    // }
    // cout<<endl;

}

int main() {
    
    int num;
    
    cout<<"Please enter a positive integer: \n";
    cin>>num;
    
    //cout<<"section a"<<endl;
    //cout<<"section b"<<endl;
    if (num < 2)
        cout<<"Please enter a valid input >= 2"<<endl;
    else
        printDivisors(num);
    
    return 0;
}
