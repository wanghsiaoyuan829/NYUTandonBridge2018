//
//  nn1338_hw6_q2.cpp
//  nn1338_hw6_q2
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 A palindrome is a word, which reads the same backward or forward. For example, noon, civic,
 radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer are all palindromes.
 a. Implement a function:
    bool isPalindrome(string str)
    This function is given a string str containing a word, and returns true if and only if str is
    a palindrome.
 
 b. Write a program that reads a word from the user and announces to the user if it is a
    palindrome or not.
    Your program should interact with the user exactly as it shows in the following example:
    Please enter a word: level
    level is a palindrome

*/

#include <iostream>
#include <string>

using namespace std;

// Compiler order to use the function isPalindrome before main
bool isPalindrome(string str);

int main() {
    
    string str;
    
    cout<<"Please enter any word to check for palindrome: ";
    cin>>str;
    
    //Call isPalindrome function
    isPalindrome(str);
    
    return 0;
}

bool isPalindrome(string str) {
    
    // True or false variable
    bool flag = false;
    // Word length
    long wordLength = str.length();
    
    for (int i = 0; i < wordLength; i++) {
        // Check if first string matches with last string, second string matches with second to last string etc.
        if(str[i] == str[wordLength - i - 1]) {
            // if matched, set flag variable to true
            flag = true;
        }
        else {
            // else if letters do not match, set flag variable to false
            // and if it is false, break the loop to not waste computation time
            flag = false;
            break;
        }
    }
    
    // Output to user if the word is a palindrome or not
    if (flag == false) {
        cout<<str<<" is not a palindrome \n";
    } else {
        cout<<str<<" is a palindrome \n";
    }
    
    // Return the flag value
    return flag;
}
