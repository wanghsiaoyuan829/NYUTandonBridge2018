//
//  main.cpp
//  nn1338_hw7_q3
//
//  Created by NomNomNam on 5/29/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Implement the function:
 void oddsKeepEvensFlip(int arr[], int arrSize)
 
 This function gets an array of integers arr and its logical size arrSize. When called, it should reorder (in-place) the elements of arr so that:
 1. All the odd numbers come before all the even numbers
 2. The odd numbers will keep their original relative order
 3. The even numbers will be placed in a reversed order (relative to their original order).
 
 For example, if arr = [5, 2, 11, 7, 6, 4],
 after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]
 
 Implementation requirements:
 1. Your function should run in linear time. That is, if there are n items in arr, calling
 oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
 2. Write a main() program that tests this function..
 
 */

#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    
    // Test sample array
    int arr[] = {5, 2, 11, 7, 6, 4};
    
    // Call void function
    oddsKeepEvensFlip(arr, 6);
    
    // Print to user
    cout<<"Odds Keep & Evens Flip:\n";
    for (int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* tempArr;
    tempArr = new int[arrSize];
    int i, index = 0;
    
    // If current element is odd, add odds into tempArr
    for (i = 0; i < arrSize; i++)
        if ((arr[i] % 2 == 1))
            tempArr[index++] = arr[i];
    
    // Continue the chain of array after odds are added to array
    // If curr element is even, add even elements in reverse order
    for (i = arrSize; i >= 0; i--)
        if (arr[i] % 2 == 0)
            tempArr[index++] = arr[i];
    
    // Add values of tempArr back to arr
    for (i = 0; i < arrSize; i++) {
        arr[i] = tempArr[i];
    }
    
    // Free memory allocation
    delete [] tempArr;
    tempArr = arr;
}
