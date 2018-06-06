//
//  nn1338_hw8_q1.cpp
//  nn1338_hw8_q1
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Give a recursive implement to the following functions:
 a. void printTriangle(int n)
    This function is given a positive integer n, and
    prints a textual image of a right triangle
    (aligned to the left) made of n lines with asterisks.
    For example, printTriangle(4), should print:
    *
    **
    ***
    ****
 b. void printOpositeTriangles(int n)
 This function is given a positive integer n, and
 prints a textual image of a two opposite right
 triangles (aligned to the left) with asterisks, each containing n lines.
 For example, printOpositeTriangles(4), should print:
    ****
    ***
    **
    *
    *
    **
    ***
    ****
 c. void printRuler(int n)
 prints a vertical ruler of 2" − 1 lines. Each line contains ‘-‘ marks as follows:
 • The line in the middle (1/2) of the ruler contains n ‘-‘ marks
 • The lines at the middle of each half (1/4 and 3/4 of the ruler contains (n-1) ‘-‘ marks
 • The lines at the 1/8, 3/8, 5/8, 7/8 of the ruler contains (n-2) ‘-‘ marks
 
 And so on ...
 For example, printRuler(4), should print (only the blue marks):
 - 1/16= -- 2/16= - 3/16= --- 4/16= - 5/16= -- 6/16= - 7/16= ---- 8/16= - 9/16= -- 10/16= - 11/16= --- 12/16= - 13/16= -- 14/16= -
 
 Hints:
 1. Take for n=4: when finding print_ruler(4), try to think first what
    print_ruler(3) does, and how you can use it to print a ruler of size 4.
    Then, generally identify what print_ruler(n-1) is supposed to print, and use that
    in order to define how to print the ruler of size n.
 2. You may want to have more than one recursive call
 3. It looks much scarier than it actually is
 
*/

#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {
    
    cout<<"Section A\n";
    printTriangle(4);
    cout<<endl;

    cout<<"Section B\n";
    printOpositeTriangles(4);
    cout<<endl;
    
    cout<<"Section C\n";
    printRuler(4);
    cout<<endl;
    
    return 0;
}

void printTriangle(int n) {
    int currLine = 1;
    
    if (currLine == n)
        cout<<"*"<<endl;
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++)
            cout<<"*";
        cout<<endl;
    }
}

void printOpositeTriangles(int n) {
    int baseLine = 1;
    
    if (baseLine == n) {
        cout<<"*"<<endl;
        cout<<"*"<<endl;
    }
    else {
        for (int i = 0; i < n; i++)
            cout<<"*";
        cout<<endl;
        
        printOpositeTriangles(n-1);
        
        for (int i = 0; i < n; i++)
            cout<<"*";
        cout<<endl;
    }
}

void printRuler(int n) {

    if (n > 1)
        printRuler(n - 1);
    cout<<endl;
    
    for (int i = 0; i < n; i++)
        cout<<"-";
    
    if (n > 1)
        printRuler(n - 1);
    
}
