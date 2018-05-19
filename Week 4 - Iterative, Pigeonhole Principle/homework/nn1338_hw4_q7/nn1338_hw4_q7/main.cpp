//
//  main.cpp
//  nn1338_hw4_q7
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that reads a positive integer n from the user and prints out a nxn
 multiplication table. The columns should be spaced by a tab.
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a positive integer:
 10
 1 2 3 4 5 6 7 8 9 10
 2 4 6 8 10 12 14 16 18 20
 3 6 9 12 15 18 21 24 27 30
 4 8 12 16 20 24 28 32 36 40
 5 10 15 20 25 30 35 40 45 50
 6 12 18 24 30 36 42 48 54 60
 7 14 21 28 35 42 49 56 63 70
 8 16 24 32 40 48 56 64 72 80
 9 18 27 36 45 54 63 72 81 90
 10 20 30 40 50 60 70 80 90 100
 
 */

#include <iostream>
using namespace std;

int main() {
    
    int row;
    int column;
    int integer = 5;
    
//    cout<<"Please enter a positive integer:"<<endl;
//    cin>>integer;
    
    // Nested for loops for rows and inside rows is columns
    // Increment rows and columns until >= user input
    for (row = 0; row < integer; row++) {
        if (row == 0) {
            cout<<"Mon Tue Wed Thu Fri Sat Sun"<<endl;
        }
        for (column = 0; column < integer; column++) {
            // \t is tab
            // Math formula for matrix multiplication table
            cout<<(column + 1) * (row + 1) << '\t';
        }
        // New line
        cout<<endl;
    }
    return 0;
}
