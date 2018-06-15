//
//  main.cpp
//  nn1338_hw5_q2
//
//  Created by NomNomNam on 5/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 Write a program that, prints a ‘pine tree’ consisting of triangles of increasing sizes, filled
 with a character (eg. ‘*’ or ’+’ or ‘$’ etc).
 Your program should interact with the user to read the number of triangles in the tree and the character filling the tree.
 
 Your implementation should include the following functions:
 a. void printShiftedTriangle(int n, int m, char symbol)
 
 For example, if we call printShiftedTriangle(3, 4, `+`), the expected output is:
   +
  +++
 +++++
 
 b. void printPineTree(int n, char symbol)
 It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line triangle), which form the shape of a pine tree. The triangles are filled with the symbol character.
 For example, if we call printPineTree(3, `#`), the expected output is:
   #
  ###
   #
  ###
 #####
   #
  ###
 #####
#######
*/

/*
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    
    int n, m;
    char symbol;
    
    cout<<"Enter the number of lines: \n";
    cin>>n;
    
    cout<<"Enter the number of spaces: \n";
    cin>>m;
    
    cout<<"Enter the character symbol (+, #, @, *): \n";
    cin>>symbol;
    
    
//    printShiftedTriangle(n, m, symbol);
    printPineTree(n, symbol);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int line, countChar, addSpace;
 
    for (line = 0; line < n; line++) {
        for (countChar = 1; countChar <= m ; countChar++)
            cout << " ";
            for (addSpace = 1; addSpace < n - line; addSpace++) {
                cout << " ";
        }
        for (countChar = 1; countChar <= (2 * line) + 1; countChar++)
            cout<< symbol;
        cout << endl;
    }
}

*/

#include <iostream>
using namespace std;

// Use for section A for printShiftedTriangle
// void printShiftedTriangle(int n, int m, char symbol) {
//    int line, countChar, addSpace;
//
//    for (line = 0; line < n; line++) {
//        for (countChar = 1; countChar <= m ; countChar++)
//            cout << " ";
//            for (addSpace = 1; addSpace < n - line; addSpace++) {
//                cout << " ";
//            }
//        for (countChar = 1; countChar <= (2 * line) + 1; countChar++)
//            cout<< symbol;
//        cout << endl;
//    }
// }


// Use for section B for printedShiftedTriangle
void printShiftedTriangle(int n, int m, char symbol) {
    int line, countChar, countSymbol;

    countSymbol = 1;

    for (line = 1; line <= n; line++) {
        // Print spaces if count is less than
        for (countChar = 1; countChar <= m; countChar++) {
            cout << " ";
        }
        // print characters
        for (countChar = 1; countChar <= countSymbol; countChar++) {
            cout << symbol;
        }

        m--;
        countSymbol += 2;

        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int triangle = 1; triangle <= n ; triangle++)
        printShiftedTriangle(triangle + 1, n, symbol);
}

int main() {

    int n, m;
    char symbol;
    
    cout<<"Enter the number of triangles: ";
    cin>>n;
    
    //Section A
    cout<<"Enter the number of spaces: ";
    cin>>m;
    
    cout<<"Enter the character symbol (+, #, @, *): ";
    cin>>symbol;
    
    printShiftedTriangle(n, m, symbol);
    printPineTree(n, symbol);
    
    return 0;
}
