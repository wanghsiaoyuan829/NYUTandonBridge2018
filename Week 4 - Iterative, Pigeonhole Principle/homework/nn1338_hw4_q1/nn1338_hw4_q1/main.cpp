//
//  main.cpp
//  nn1338_hw4_q1
//
//  Created by NomNomNam on 5/6/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Write two versions of a program that reads a positive integer n, and prints the first n even numbers.
 a) In the first, use a while loop.
 b) In the second, use a for loop.
 
 Each section should interact with the user exactly as it shows in the following example:
 Please enter a positive integer: 3
 2
 4
 6

*/
#include <iostream>
using namespace std;

int main() {
    
    int posInt;
    int count;
    
    cout<<"Please enter a positive integer: ";
    cin>>posInt;
    
    // Start with count 1
    count = 1;
    
    // While count is less than or equal to user input (e.g.) count will increase from 1 to 2 to 3
    // and break the condition there. Each iteration will print out count multiplied by 2
    while (count <= posInt) {
        cout<<count*2<<endl;
        count++;
    }
    
    return 0;
}
