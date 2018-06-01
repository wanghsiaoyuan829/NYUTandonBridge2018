//
//  main.cpp
//  nn1338_hw7_q5
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 In this question, you will write four versions of a function getPosNums that gets an array of integers arr, and its logical size. When called it creates a new array containing only the positive numbers from arr.
 For example, if arr=[3, -1, -3, 0, 6, 4], the functions should create an array containing the following 3 elements: [3, 6, 4],
 
 The four versions you should implement differ in the way the output is returned. The prototypes of the functions are:
 a) int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
 returns the base address of the array (containing the positive numbers), and updates the output parameter outPosArrSize with the array’s logical size.
 
 b) void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
 updates the output parameter outPosArr with the base address of the array (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.
 
 c) int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) returns the base address of the array (containing the positive numbers), and uses the pointer outPosArrSizePtr to update the array’s logical size.
 
 d) void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
 uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.
 
 Note: You should also write a program that calls and tests all these functions.
 
 */

#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArrayValue(int* arr,int arrSize);

int main() {
    
    // Initialize fixed variables to test functions
    int arr[] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;
    int outPosArrSize;
    int* outPosArr;
    
    cout<<"Version A:\n";
    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
    printArrayValue(outPosArr, outPosArrSize);
    
    cout<<"Version B:\n";
    getPosNums2(arr, arrSize, outPosArr, outPosArrSize);
    printArrayValue(outPosArr, outPosArrSize);
    
    cout<<"Version C:\n";
    outPosArr = getPosNums3(arr, arrSize, &outPosArrSize);
    printArrayValue(outPosArr, outPosArrSize);
    
    cout<<"Version D:\n";
    getPosNums4(arr, arrSize, &outPosArr, &outPosArrSize);
    printArrayValue(outPosArr, outPosArrSize);
    
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    
    // Increment array size based on the number of positive numbers
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize++;
        }
    }
    
    // Store final value of outPosArrSize as the size of the dynamic array variable outPosArr
    // Updates the output parameter outPosArrSize with the array’s logical size
    int* outPosArr = new int[outPosArrSize];
    int i, j = 0;
    
    // Store all positive numbers to outPosArr
    for (i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[j++] = arr[i];
        }
    }
    
    // Returns the base address of the array
    return outPosArr;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    
    // Increment array size based on the number of positive numbers
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize++;
        }
    }
    
    // Store final value of outPosArrSize as the size of the dynamic array variable outPosArr
    // Updates the output parameter outPosArr with the base address of the array (containing the positive numbers)
    outPosArr = new int[outPosArrSize];
    int i, j = 0;
    
    // Store all positive numbers to outPosArr
    for (i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[j++] = arr[i];
        }
    }
    
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    
    // Use the pointer to update the array's logical size
    *outPosArrSizePtr = 0;
    
    // Increment array size based on the number of positive numbers
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrSizePtr)++;
        }
    }
    
    // Store final value of outPosArrSize as the size of the dynamic array variable outPosArr
    // Updates the output parameter outPosArr with the base address of the array (containing the positive numbers)
    int* outPosArr = new int[(*outPosArrSizePtr)];
    int i, j = 0;
    
    // Store all positive numbers to outPosArr
    for (i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[j++] = arr[i];
        }
    }
    
    // returns the base address of the array (containing the positive numbers)
    return outPosArr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    
    // Use the pointer outPosArrSizePtr to update the array’s logical size
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrSizePtr)++;
        }
    }
    
    // Use the pointer outPosArrPtr to update the base address of the array
    // (containing the positive numbers)
    (*outPosArrPtr) = new int[(*outPosArrSizePtr)];
    int i, j = 0;
    
    // Store all positive numbers to outPosArrPtr
    for (i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[j++] = arr[i];
        }
    }
    
}

void printArrayValue(int* arr,int arrSize) {
    
    cout<<"New positive nums array: ";
    
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl<<endl;
}
