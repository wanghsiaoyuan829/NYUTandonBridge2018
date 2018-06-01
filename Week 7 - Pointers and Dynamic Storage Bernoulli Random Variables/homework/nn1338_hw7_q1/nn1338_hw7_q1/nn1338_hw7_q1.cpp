//
//  main.cpp
//  nn1338_hw7_q1
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*

 Write a program that will read in a line of text and output the number of words in the line and
 the number of occurrences of each letter.
 Define a word to be any string of letters that is delimited at each end by either whitespace, a
 period, a comma, or the beginning or end of the line.
 You can assume that the input consists entirely of letters, whitespace, commas, and periods.
 When outputting the number of letters that occur in a line, be sure to count upper and
 lowercase versions of a letter as the same letter.
 Output the letters in alphabetical order and list only those letters that do occur in the input line.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter a line of text:
 I say Hi.
 3  words
 1  a 
 1  h 
 2  i 
 1  s
 1  y 
 
 Notes:
 1.  Think how to break down your implementation to functions.
 2.  Pay attention to the running time of your program. If the input line contains 𝑛 characters, an
 efficient implementation would run in a linear time (that is Θ 𝑛 ).
 
*/

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

int main(){
    string line;
    
    cout << "Please enter a line of text: \n";
    getline(cin, line);
    
    int letterArr[26] = {0}; // 26 letters in the alphabet
    int wordCount = 0; // Keep track of how many words there are in a sentence
    
    for(int i = 0; i < line.size(); i++) {
        // Check if values in line are between lowercase and uppercase letters A to Z
        // Check if punctuations and empty spaces are followed after a letter,
        // then it is considered a word
        // Increment word count
        if ( ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
            && (line[i + 1] == ' ' || line[i + 1] == ',' || line[i + 1] == '.'))
            wordCount++;
        // If upper case
        // Increment letter count of that specific letter stored in the array
        // Subtract the char value of 'A' to the line[i] char to get the proper count
        if (line[i] >= 'A' && line[i] <= 'Z')
            letterArr[line[i] - 'A']++;
        // If lower case
        if (line[i] >= 'a' && line[i] <= 'z')
            letterArr[line[i] - 'a']++;
    }
    
    // Print out word count to user
    cout<<wordCount<<"\twords"<<endl;
    
    // Iterate over the letter array keeping track of the counts of each letter that appeared
    for (int i = 0; i < ALPHABET_SIZE; i++){
        // If letter array value count is higher than 1
        if(letterArr[i] > 0)
            // Print out value of letter array
            // Cast int i to char. Print out char 'a' + i to get the actual char value that was
            // higher than 1 letter count in the letter array
            cout<<letterArr[i]<<"\t"<<(char)('a' + i)<<endl;
    }
    
    return 0;
}
