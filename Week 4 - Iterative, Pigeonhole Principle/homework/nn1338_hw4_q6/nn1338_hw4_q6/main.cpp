//
//  main.cpp
//  nn1338_hw4_q6
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that asks the user to input a positive integer n, and print all of the numbers from 1 to n that have more even digits than odd digits.
 For example, if n=30, the program should print:
 2
 4
 6
 8
 20
 22
 24
 26
 28
 
*/

#include <iostream>
using namespace std;

int main() {
    
    int evensCount, oddsCount;
    int i;
    int number, remainder;
    int original_number;
    bool loop;
    
    cout<<"Please enter in an evens positive integer"<<endl;
    cin>>number;
    
    original_number = number;
    loop = false;
    
    // Initialize i = 1
    // Increment i until i >= user input
    for (i = 1; i < original_number; i++) {
        // Check for evens
        if (i % 2 == 0 ) {
            evensCount = 0;
            oddsCount = 0;
            // While loop condition is met ...
            while (loop == false) {
                // Keep track of evens and odds count
                remainder = number % 10;
                if (remainder % 2 == 0) {
                    evensCount += 1;
                    if (evensCount > 10)
                        loop = true;
                }
                else {
                    oddsCount += 1;
                    if (oddsCount >= evensCount)
                        break;
                }
                // Reset number
                number = i / 10;
            }
            
            // Reset loop value to false
            loop = false;
            
            // If there are more evens count, print i to the user
            if (evensCount > oddsCount)
                cout<<i<<endl;
            
            // Start iterative loop over with the original value
            number = original_number;
        }
    }
    
    return 0;
}
