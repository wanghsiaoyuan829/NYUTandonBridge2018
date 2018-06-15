//
//  main.cpp
//  readLines
//
//  Created by NomNomNam on 6/7/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

string* readLinesArray1(int& outLinesArrSize);
string* readLinesArray2(int& outLinesArrSize);
vector<string> readLinesVector();

int main() {
    //string* linesArr;
    //int linesArrSize;
    vector<string> linesVector;
    
    //linesArr = readLinesArray2(linesArrSize);
    linesVector = readLinesVector();
    
    cout<<"Your text is:"<<endl;
    for (int i=0; i<linesVector.size(); i++) {
        cout<<linesVector[i]<<endl;
    }
    return 0;
}

string* readLinesArray1(int& outLinesArrSize){
    int linesArrSize;
    string* linesArr;
    string temp;
    
    cout<<"Please enter number of lines:"<<endl;
    cin>>linesArrSize;
    getline(cin, temp);
    
    linesArr = new string[linesArrSize];
    
    cout<<"Enter "<<linesArrSize<<" lines:"<<endl;
    for (int i=0; i<linesArrSize; i++) {
        getline(cin, linesArr[i]);
    }
    
    outLinesArrSize = linesArrSize;
    return linesArr;
}

string* readLinesArray2(int& outLinesArrSize){
    string* lines;
    int linesSize, linesPhysicalSize;
    bool seenEmptyLine;
    string currLine;
    
    cout<<"Please enter lines of text"<<endl;
    cout<<"End your input with an empty line"<<endl;
    
    lines = new string[1];
    linesPhysicalSize = 1;
    linesSize = 0;
    
    seenEmptyLine = false;
    while (seenEmptyLine == false) {
        getline(cin, currLine);
        if (currLine == "")
            seenEmptyLine = true;
        else{
            if(linesSize == linesPhysicalSize){
                //resize (double) the array
                string* newLines;
                newLines = new string[2* linesPhysicalSize];
                for (int i=0; i<linesSize; i++) {
                    newLines[i] = lines[i];
                }
                delete [] lines;
                lines = newLines;
                linesPhysicalSize *= 2;
            }
            lines[linesSize] = currLine;
            linesSize++;
        }
    }
    
    outLinesArrSize = linesSize;
    return lines;
}

vector<string> readLinesVector(){
    vector<string>  lines;
    bool seenEmptyLine;
    string currLine;
    
    cout<<"Please enter lines of text"<<endl;
    cout<<"End your input with an empty line"<<endl;
    
    seenEmptyLine = false;
    while (seenEmptyLine == false) {
        getline(cin, currLine);
        if (currLine == "")
            seenEmptyLine = true;
        else{
            lines.push_back(currLine);
        }
    }
    
    return lines;
}
