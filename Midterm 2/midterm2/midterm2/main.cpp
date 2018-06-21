//
//  main.cpp
//  midterm2
//
//  Created by NomNomNam on 6/7/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 Please enter a positive integer:
 5
 The first 5 positive integers are: 1  2  3  4  5
 */

#include <iostream>
using namespace std;

void firstPosIntsArr(int n, int arr[], int& arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int n;
    int* arr;
    int arrSize;
    
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;
    
    arr = new int(n);
    
    firstPosIntsArr(n, arr, arrSize);  // calling your function
    
    cout<<"The first "<<arrSize<<" positive integers are: ";
    printArray(arr, arrSize);
    cout<<endl;
    
    delete []arr;
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for(i = 0; i < arrSize; i++)
        cout<<arr[i]<<" ";
}

void firstPosIntsArr(int n, int arr[], int& arrSize) {
    arrSize = 0;
    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        arrSize++;
    }
    
}

