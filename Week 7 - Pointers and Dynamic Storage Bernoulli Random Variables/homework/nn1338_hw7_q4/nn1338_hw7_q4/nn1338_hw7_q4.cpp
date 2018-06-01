//
//  main.cpp
//  nn1338_hw7_q4
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Implement the function:
 string* createWordsArray(string sentence, int& outWordsArrSize)
 
 This function gets a string sentence containing a sentence.
 When called, it should create and return a new array (of strings), that contains all the words in sentence. The function should also update the output parameter, outWordsArrSize, with the logical size of the new array that was created.
 
 Note: Assume that the words in the sentence are separated by a single space.
 
 For example, if sentence=”You can do it”, after calling createWordsArray(sentence, outWordsArrSize), the function should create and return an array that contains [”You” , ”can” , ”do” , ”it”], and update the value in outWordsArrSize to be 4.
 
 Implementation requirements:
 1. You may want to use some of the string methods, such as find, substr, etc.
 2. Your function should run in linear time. That is, if sentence contains n characters,
 your function should run in 𝜃(𝑛).
 3. Write a main() program that tests this function..
 
 */

#include <iostream>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    
    // Initialize variables
    string sentence;
    string* words; // word pointer
    int outWordsArrSize = 0;
    
    // Print to user and store user input in sentence
    cout<<"Please enter a sentence:\n";
    getline(cin, sentence);
    
    // Store the return value of the function createWordsArray in words variable
    words = createWordsArray(sentence, outWordsArrSize);
    
    // Print out each value in the words variable
    cout<<"Words array of size "<<outWordsArrSize<<" contain:\n";
    for (int i = 0; i < outWordsArrSize; i++) {
        cout<<words[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}

// Store a string of sentence in a new array
// Intput: string sentence and logic array size
// Output: new array
string* createWordsArray(string sentence, int& outWordsArrSize) {
    
    // Iterating over sentence string to find spaces. Each space = one word.
    // Increment outWordsArrSize
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ')
            outWordsArrSize++;
    }
    
    // Since outwords size starts at 0, add 1 to get the real size value
     outWordsArrSize++;
    
    // Dynamically create word array based on outWordsArrSize
    string* words = new string[outWordsArrSize];
    int wordCounter = 0;
    
    for (int i = 0; i < sentence.length(); i++) {
        // Check for spaces. If there are spaces, increment wordCounter
        if (sentence[i] == ' ') {
            wordCounter++;
            i++;
        }
        // Sentence characters are added one by one into words indices until a space
        // is encountered, then wordCounter increments by one thus increasing the index by one
        // This logic stores one word in an index of the words array
        words[wordCounter] += sentence[i];
    }
    
    return words;
}

