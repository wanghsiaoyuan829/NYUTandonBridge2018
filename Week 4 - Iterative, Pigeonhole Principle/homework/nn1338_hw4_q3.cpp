//
//  main.cpp
//  nn1338_hw4_q3
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Write a program that reads from the user a positive integer (in a decimal representation), and
 prints its binary (base 2) representation.
 
 Your program should interact with the user exactly as it shows in the following example:
 Enter decimal number:
 76
 The binary representation of 76 is 1001100
 
*/

#include <iostream>
using namespace std;

int main() {

    int num, original_num;
    int remainder;
    string binaryRepresentation;
    string reverseBinaryRepresentation;
    
    cout<<"Enter decimal number:"<<endl;
    cin>>num;
    
    // Num will be modified in the while loop, so the original value is stored in original_num
    original_num = num;
    // Initialize binary representation as an empty string
    binaryRepresentation = "";
    
    // When num, in this case quotient = 0, the while loop will break outputting binary representation
    while (num != 0) {
        // The value of the remainder will be the binary representation
        remainder = num % 2;
        
        // Restoring new value of the quotient after each iteration
        num = num / 2;
        
        // Casting remainder integer to string and concatenating the strings
        binaryRepresentation += std::to_string(remainder);
    }
    
    // Reversing the binary representation string output
    reverseBinaryRepresentation = string(binaryRepresentation.rbegin(), binaryRepresentation.rend());
    
    // Output reverseBinaryRepresentation to the user
    cout<<"The binary representation of "<<original_num<<" is "<<reverseBinaryRepresentation<<endl;
    
    return 0;
}
