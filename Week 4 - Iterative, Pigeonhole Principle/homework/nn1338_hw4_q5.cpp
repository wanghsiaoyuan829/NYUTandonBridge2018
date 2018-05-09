//
//  main.cpp
//  nn1338_hw4_q5
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Write a program that asks the user to input a positive integer n, and prints a textual image of an
 hourglass made of 2n lines with asterisks.
 For example if n=4, the program should print:
 *******
  *****
   ***
    *
    *
   ***
  *****
 *******
 
*/

#include <iostream>
using namespace std;

int main() {
    
    int number;
    int line, count;
    
    cout<<"Please enter a positive integer:"<<endl;
    cin>>number;
    
    // Top half of hourglass for loop (Line = user input then decrease from there until line = 0. e.g. if 4 is the input, will print out 4 lines)
    // Logic for inverted triangle of the hourglass.
    for (line = number; line > 0; line--) {
        // Blank spaces added when line value is greater than count.
        for (count = number; line < count; count--)
            cout << " ";
        // Concatenate asterisks: left side
        // Count is initialized to 1 to accommodate for the (-1) offset value of printed asterisks
        for (count = 1; line > count; count++)
            cout << "*";
        // Concatenate asterisks: right side
        for (count = 0; line > count; count++)
            cout << "*";
        // Breaks a new line after the count loops
        cout << endl;
    }
    
    // Bottom half of hourglass for loop (Line = 0 then increase until line = user input.)
    // Logic for upright triangle of the hourglass.
    for (line = 0; line < number; line++) {
        // Print concatenated blank spaces. The +1 logic accounts for the asterisk(s) being concatenated.
        for (count = 0; count < (number - (line + 1)); count++)
            cout << " ";
        // Count is initialized to 1 to accommodate for the (-1) offset value of printed asterisks
        // After each iteration, count is being added to the previous value of count by 1
        // 2 * line + 1 is the formula for the added asterisks after each loop. 2 more asterisks gets added after each loop.
        for (count = 1; count <= (2 * line) + 1; count++)
            cout << "*";
        cout << endl;
    }
    
    return 0;
}
