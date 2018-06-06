//
//  main.cpp
//  nn1338_hw8_q2
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Give a recursive implement to the following functions:
 a. int sumOfSquares(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize. When called,
    it returns the sum of the squares of each of the values in arr.
    For example, if arr is an array containing [2, -1, 3, 10],
    calling will return 114 (since, 22 + (-1)2 + 32 + 102 = 114).
 b. bool isSorted(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize. When called, it
    should return true if the elements in arr are sorted in an ascending order, or false
    if they are not.
 
 */

#include <iostream>
#include <cmath>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[] = {2, -1, 3, 10};
    int arrSize = 4;
    
    // Initialize the sum to be the return value of the function call
    int sum = sumOfSquares(arr, arrSize);
    
    // Print out to user the sum of squares
    cout<<"The sum of squares is: "<<sum<<endl;
    
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    // Base case: if arrSize is 0 or the first element of the array
    if (arr[arrSize] == arr[0]) {
        // exit
        return 0;
    }
    else {
        int resultPower = pow(arr[arrSize - 1], 2);
        return (sumOfSquares(arr, arrSize - 1) + resultPower);
    }
}
