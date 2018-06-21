//
//  main.cpp
//  createNumbersArray
//
//  Created by NomNomNam on 6/7/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

// numsStr="32 5 43 712" --> [32,5, 43,712]

#include <iostream>

using namespace std;

int* createNumbersArray(string numsStr, int& outNumsArrSize);

int main() {
    int outNumsArrSize = 0;
    string numStr;
    
    cout<<"Please enter a string of integers separated by a space:\n";
    getline(cin, numStr);
    
    int* createNum = createNumbersArray(numStr, outNumsArrSize);
    
    cout<<"Your string to array elements are: ";
    for (int i = 0; i < outNumsArrSize; i++) {
        cout<<createNum[i]<<" ";
    }
    
    delete [] createNum;
    createNum = NULL;
    
    cout<<endl;
    
    return 0;
}

int* createNumbersArray(string numsStr, int& outNumsArrSize) {
    int currSize = 0;
    int* numsArr;
    
//    spliceNumsStr = numsStr.find(' ');
    
    numsArr = new int[outNumsArrSize];
    
    for (int i = 0; i < numsStr.length() + 1; i++) {
        numsArr[i] = numsStr[i];
        currSize++;
    }
    
    outNumsArrSize = currSize;
    
    return numsArr;
}



