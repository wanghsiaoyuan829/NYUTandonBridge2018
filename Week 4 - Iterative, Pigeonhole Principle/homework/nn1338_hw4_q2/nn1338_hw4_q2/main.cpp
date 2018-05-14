//
//  main.cpp
//  nn1338_hw4_q2
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 In this question we will use a simplified version of the Roman Numerals System to represent
 positive integers.
 
 The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value, as
 showed in the following table:
 

 A number in the simplified Roman numerals system is a sequence of Roman digits, which follow
 these 2 rules:
 
 1. The digits form a monotonically non-increasing sequence. That is the value of each digit is
 less than or equal to the value of the digit that came before it.
 For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is
 not.
 
 2. There is no limit on the number of times that ‘M’ can appear in the number.
 ‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
 ‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.
 
 For example: IIII, XVII and MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman
 numeral system, but IIIII, XIV, VVI and CCXLIII are not.
 Write a program that reads from the user a (decimal) number, and prints it’s representation in
 the simplified Roman numerals system.

 Your program should interact with the user exactly as it shows in the following example:
 Enter decimal number:
 147
 147 is CXXXXVII
 
 */
#include <iostream>
using namespace std;

int main() {
    
    // 147 = CXXXXVII
    int decNum;
    int originalDecNum;
    string romanDig = "";
    
    // Store user input
    cout<<"Enter decimal number:"<<endl;
    cin>>decNum;
    
    // Later on, the user input of decNum will change, so this variable will store the original decNum value to print the value back
    // to the user at the end of the algorithm
    originalDecNum = decNum;
    
    // Multiply the roman digits by the amount of times it is divisible by the user input value
    // Take the remainder of the input value to find the next series of roman digits.
    // 147 % 100 = 47. Since it already printed out a 'C', the next step is to find what else divides into 47.
    romanDig = string(decNum/1000, 'M');
    decNum %= 1000;
    romanDig += string(decNum/500, 'D');
    decNum %= 500;
    romanDig += string(decNum/100, 'C');
    decNum %= 100;
    romanDig += string(decNum/50, 'L');
    decNum %= 50;
    romanDig += string(decNum/10, 'X');
    decNum %= 10;
    romanDig += string(decNum/5, 'V');
    decNum %= 5;
    romanDig += string(decNum/1, 'I');
    
    cout<<originalDecNum<<" is "<<romanDig<<endl;
    
    return 0;
}
