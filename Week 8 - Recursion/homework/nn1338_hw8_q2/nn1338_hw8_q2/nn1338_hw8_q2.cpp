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
    
    if (isSorted(arr, arrSize) == true)
        cout<<"All nums in the array are sorted\n";
    else
        cout<<"The nums in the array are NOT sorted\n";
    
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
        
        // Recursive function
        // Function returns 0 but adding resultPower will give it the sum of the square
        return (sumOfSquares(arr, arrSize - 1) + resultPower);
    }
}

bool isSorted(int arr[], int arrSize) {
    
    // Base Case:
    // 0 and 1 elements are considered already sorted
    if (arrSize == 0 || arrSize == 1)
        return true;
    else {
        // if the latter element is less than the former element in the array
        // it is considered NOT sorted, return false
        if (arr[arrSize - 1] < arr[arrSize - 2])
            return false;
        // Else call recursive function to decrease arrSize
        else
            return isSorted(arr, arrSize - 1);
        
    }
}
