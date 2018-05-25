//
//  nn1338_hw6_q6.cpp
//  nn1338_hw6_q6
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that reads in a line of text and outputs the line with all the digits in all integer numbers replaced with 'x'.  
 Please enter a line of text:
 My userID is john17 and my 4 digit pin is 1234 which is secret
 My userID is john17 and my x digit pin is xxxx which is secret
 
 Notes:
 1. If a digits is part of a word, then the digit is not changed to an 'x'. For example, john17 is
    NOT changed to johnxx.
 2. You may assume that the text entered by the user will contain only letters (upper case or
    lower case), digits and spaces.
 3. Think how to break down your implementation to functions.
 
 */

#include <iostream>
#include <sstream> // Use C++ library
using namespace std;

int main() {
    
    string sentence;
    cout<<"Please enter a line of text:\n";
    // Test using: 17hello hello17 17 17 171717 17hell17hell17
    getline(cin, sentence);
    
    // Initialize variables
    istringstream iss(sentence);
    string characters;
    string x_sentence="";
    
    while(iss >> characters) {
        // Use C++ find_first_not_of method
        // If within the word there are string digits, then replace with 'x'
        if(characters.find_first_not_of("0123456789") == string::npos) {
            for(int i = 0; i < characters.size(); i++)
                x_sentence += 'x';
            // If there are no string digits, then append the non digits to the new string
        } else
            x_sentence.append(characters);
        // Add spaces between words
        x_sentence += ' ';
    }
    
    cout<<x_sentence<<endl;
    
    return 0;
}
