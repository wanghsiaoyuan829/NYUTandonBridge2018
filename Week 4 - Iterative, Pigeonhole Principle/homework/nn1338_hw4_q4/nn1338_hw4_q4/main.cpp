//
//  main.cpp
//  nn1338_hw4_q4
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write two versions of a program that reads a sequence of positive integers from the user,
 calculates their geometric mean, and print the geometric mean.
 Notes:
 1. In mathematics, geometric mean of a dataset {a1, a2, a3 ..., an} containing positive numbers, is given by: the nth root of the set a1*a2*a3...an.
    For example, the geometric mean of 2, 9 and 12 is equal to 6
 2. In order to calculate the n-th root of a number, you should call the pow funciton, located in the cmath library.

 Your two versions should read the integer sequence in two ways:
 a) First read the length of the sequence.
 For example, an execution would look like:
 Please enter the length of the sequence: 3
 Please enter your sequence:
 1
 2
 3
 The geometric mean is: 1.8171
 
 b) Keep reading the numbers until -1 is entered.
 For example, an execution would look like:
 Please enter a non-empty sequence of positive integers, each one in a separate line. End your
 sequence by typing -1:
 1
 2
 3
 -1
 The geometric mean is: 1.8171
 
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int currElement;
    int count;
    double lengthOfSequence, numSequence;
    double result, geometricMean;
    bool seenEndOfSeq;
    
    cout<<"section a"<<endl;
    
    cout<<"Please enter the length of the sequence: ";
    cin>>lengthOfSequence;
    
    cout<<"Please enter your sequence:"<<endl;
    
    count = 0;
    geometricMean = 0;
    result = 1;
    
    /* SECTION A ALGORITHM - use numSequence instead of currElement to store user input
     
    while (count <= lengthOfSequence) {
        cin>>numSequence;
        result *= numSequence;
        geometricMean = pow(result, 1/lengthOfSequence);
        count++;
    }
     
    */
    
    cout<<"section b"<<endl;
    
    seenEndOfSeq = false;
    
    // If user inputs -1, the while loop will break and output the geometric mean
    while (seenEndOfSeq == false) {
        // Store user input
        cin>>currElement;
        if (currElement == -1)
            seenEndOfSeq = true; // Break loop
        else {
            // Elements will multiply each other after each successive loop
            result *= currElement;
            // The result will be raised to the 1/n-th power to find the geometric mean
            geometricMean = pow(result, 1/lengthOfSequence);
            // Counter will keep track of loop iteration
            count++;
        }
    }
    
    // Output to user
    cout<<"The geometric mean is: "<<geometricMean<<endl;
    
    return 0;
}
