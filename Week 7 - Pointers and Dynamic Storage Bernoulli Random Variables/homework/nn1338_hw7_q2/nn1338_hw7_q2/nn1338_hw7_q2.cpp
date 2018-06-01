//
//  main.cpp
//  nn1338_hw7_q2
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Two strings are anagrams if the letters can be rearranged to form each other.
 For example, “Eleven plus two” is an anagram of “Twelve plus one”.
 Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.
 Write a program that determines if two strings are anagrams. The program should not be
 case sensitive and should disregard any punctuation or spaces.  

 Notes:
 1. Think how to break down your implementation to functions
 2. Pay attention to the running time of your program. If each input string contains 𝑛
 characters, an efficient implementation would run in a linear time (that is Θ 𝑛 ).
 
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// read two string input
// checkAnagram function
// print out Anagram or no Anagram

bool checkAnagram(string first, string second);

int main() {
    
    string first_string = "Eleven plus two", second_string = "Twelve plus one";
    bool anagram;
    
    // cout<<"Enter first string\n";
    // getline(cin, first_string);
    
    // cout<<"Enter second string\n";
    // getline(cin, second_string);
    
    anagram = checkAnagram(first_string, second_string);
    
    if (anagram == true)
        cout<<"The two strings are anagrams\n";
    else
        cout<<"The two strings are not anagrams\n";
    
    return 0;
}

bool checkAnagram(string first, string second) {
    bool anagram = false;
    int i;
    
    // lowercase the strings
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    
    // sort and store the strings in order
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    // if the length of the first and second string are not equal, then anagram is false
    if (first.length() != second.length())
        anagram = false;
    
    
    for (i = 0; i < first.length(); i++)
        if (first[i] != second[i])
            anagram = false;
        else
            anagram = true;
    
    return anagram;
}


