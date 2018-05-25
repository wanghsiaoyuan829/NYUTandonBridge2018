//
//  nn1338_hw6_q5.cpp
//  nn1338_hw6_q5
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
Write a program that reads a person’s name in the following format:
first name, then middle name or initial, and then last name.
The program then outputs the name in the following format:
Last_Name, First_Name Middle_Initial.

 For example, the input:
 Mary Average User
 should produce the output:
 User, Mary A.  
 
 The input Mary A. User   should also produce the output:   User, Mary A.  
 
 Note that your program should work the same and place a period after the middle initial even if
 the input did not contain a period.
 
 Hint: You may want to use three string variables rather than one large string variable for the
 input. You may find it easier to not use getline.  
 
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string first_name, middle_name, last_name;
    string middle_initial;
    string full_name;
    
    cout<<"Please enter your full name (i.e. Mary Average User):\n";
    cin>>first_name>>middle_name>>last_name;
    
    middle_initial = middle_name.substr(0, 1) + ".";
    
    if (middle_name == middle_initial)
        full_name = last_name + ", " + first_name + " " + middle_name;
    else
        full_name = last_name + ", " + first_name + " " + middle_initial;
    
    cout<<full_name<<endl;
    
    return 0;
}
