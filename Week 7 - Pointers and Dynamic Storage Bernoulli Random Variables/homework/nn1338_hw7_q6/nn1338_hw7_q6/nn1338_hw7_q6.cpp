//
//  main.cpp
//  nn1338_hw7_q6
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 In this question, you will write two versions of a program that reads from the user a sequence of positive integers ending with -1, and another positive integer num that the user wishes to search for.
 The program should then print all the line numbers in sequence entered by the user, that contain num, or a message saying that num does not show at all in the sequence.
 Please enter a sequence of positive integers, each in a separate line.
 End you input by typing -1.
 13
 5
 8
 2
 9
 5
 8
 8
 -1
Please enter a number you want to search.
 5
 5 shows in lines 2, 6.
 
 a) The first version of the program, is not allowed to use the vector data structure.
 b) The second version of the program, should use the vector data structure.
 
 Implementation requirements (for both programs):
 1. Think how to break down your implementation to functions.
 2. Your programs should run in linear time. That is, if there are n numbers in the input
    sequence, your program should run in 𝜃(𝑛).
 3. Write the two programs in two functions named main1() and main2(). Also have
    the main() test these two functions.
 
 */

#include <iostream>
#include <vector>

using namespace std;

string* main1(int& outLinesArrSize);
vector<string> main2();

int main () {
    string* linesArr;
    int linesArrSize;
    vector<string> linesVector;
    
    linesArr = main1(linesArrSize);
    linesVector = main2();
    
    string searchNum;
    
    cout<<"Please enter a number you want to search.\n";
    cin>>searchNum;
    
    cout<<"Version A:\n"
        <<searchNum<<" shows in lines ";
    
    for (int i = 0; i < linesArrSize; i++) {
        if (linesArr[i] == searchNum)
            cout<<i + 1<<" ";
    }
    
    cout<<endl;
    
    cout<<"Version B:\n"
        <<searchNum<<" shows in lines ";
    
    for (int i = 0; i < linesVector.size(); i++) {
        if (linesVector[i] == searchNum)
            cout<<i + 1<<" ";
    }
    
    cout<<endl;
    
    return 0;
}

string* main1(int& outLinesArrSize) {
    string* lines;
    int linesSize = 0;
    bool seenEndOfSequence = false;
    string currLine;
    
    lines = new string[linesSize];
    
    cout<<"Version A:\n";
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n"
        <<"End you input by typing -1.\n";
    
    while (seenEndOfSequence == false) {
        getline(cin, currLine);
        if (currLine == "-1") // If the user types in -1, break the while loop
            seenEndOfSequence = true;
        else {
            lines[linesSize] = currLine; // Dynamically add in new elements into array
            linesSize++;
            // Create a new dynamic array
            string* newLines;
            newLines = new string[linesSize];
            // Make a copy of the array
            for (int i = 0; i < linesSize; i++) {
                newLines[i] = lines[i];
            }
            // Reallocate memory but do not want to lose the value of lines
            // Restore lines to newLines
            delete [] lines;
            lines = newLines;
        }
    }
    
    outLinesArrSize = linesSize;
    
    return lines;
}

vector<string> main2() {
    
    vector<string> lines; // Initialize vector
    bool seenEndOfSequence = false; // Flag for while loop
    string currLine; // Store user input
    
    cout<<"Version B:\n";
    cout<<"Please enter a sequence of positive integers, each in a separate line.\n"
        <<"End you input by typing -1.\n";
    
    while (seenEndOfSequence == false) {
        getline(cin, currLine);
        if (currLine == "-1") // If the user types in -1, break the while loop
            seenEndOfSequence = true;
        else
            lines.push_back(currLine); // Dynamically add in new elements into array
    }
    
    // Return array
    return lines;
}
