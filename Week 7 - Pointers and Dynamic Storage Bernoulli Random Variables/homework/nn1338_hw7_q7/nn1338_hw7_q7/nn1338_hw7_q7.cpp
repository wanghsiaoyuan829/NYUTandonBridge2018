//
//  main.cpp
//  nn1338_hw7_q7
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Implement the function:
 int* findMissing(int arr[], int n, int& resArrSize)
 
 This function gets an array of integers arr and its logical size n. All elements in arr are in the range {0, 1, 2, ... , n}.
 Note that since the array contains n numbers taken from a range of size n+1, there must be at least one number that is missing (could be more than one number missing, if there are duplicate values in arr).
 When called, it should create and return a new array, that contains all the numbers in range {0, 1, 2, ... , n} that are not in arr. The function should also update the output parameter, resArrSize, with the logical size of the new array that was created.
 
 For example, if arr=[3, 1, 3, 0, 6, 4], after calling
 findMissing(arr, 6, resArrSize), the function should create and return an array that contains [2, 5], and update the value in resArrSize to be 2.
 
 Implementation requirements:
 1. Your function should run in linear time. That is, it should run in 𝜃(𝑛).
 2. Write a main() program that tests this function..
 
 */

#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    // Use fixed variables to test function
    int arr[] = {3, 1, 3, 0, 6, 4};
    int resArrSize;
    
    // Calling function findMissing and storing the return base value of the
    // resArray to the new missingNumArray variable
    int* missingNumArray = findMissing(arr, 6, resArrSize);
    
    // Iterate missingNumArray up to new resArrSize
    // Print to user the elements in the array
    for(int i=0; i<resArrSize; i++)
        cout<<missingNumArray[i]<<" ";
    
    cout<<endl;
    
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    
    resArrSize = n; // Store current resArrSize to original n size elements
    // Initialize new dynamic arrays
    int* tempArr = new int[n];
    int* resArray = new int[resArrSize];
    
    // tempArr = [1, 2, 3, 4, 5, 6]
    for(int i = 0; i < n; i++) {
        tempArr[i] = i + 1;
    }
    
    // Implement finding n + 1 missing num logic
    for(int i = 0; i < n; i++) {
        if(tempArr[arr[i] - 1] == arr[i]) {
            // Set tempArr elements to -1
            tempArr[arr[i] - 1] = -1;
            // Resize resArrSize subtracted from n size based on missing num elements
            resArrSize--;
        }
    }
    
    int missingNumCounter = 0;
    
    for(int i = 0; i < n; i++) {
        // iterate through the new tempArr elements and find which one
        // is greater than 0
        if(tempArr[i] > 0) {
            // store tempArr to the resArray
            // Increment the missingNumCounter based on how many elements
            // is in tempArr
            resArray[missingNumCounter] = tempArr[i];
            missingNumCounter++;
        }
    }
    
    // Update new resArrSize based on the counter of missing nums (n + 1)
    resArrSize = missingNumCounter;
    
    // Return base value of array
    return resArray;
}
