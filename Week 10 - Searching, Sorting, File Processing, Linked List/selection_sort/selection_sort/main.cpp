//
//  main.cpp
//  selection_sort
//
//  Created by NomNomNam on 6/20/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

// Selection Sort Algorithm
// n = high - low + 1
// T(n) = n + (n-1) + (n-2) + (n-3) + ... + 2 + 1 = theta(n^2)
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize) {
    int i;
    
    for (i = 0; i < arrSize; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    
}

int findIndexOfMin(int arr[], int low, int high) {
    int min, minInd;
    int i;
    
    min = arr[low];
    minInd = low;
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minInd = i;
        }
    }
    
    return minInd;
}

void selectionSort(int arr[], int arrSize) {
    int i, minInd;
    
    // Runtime Analysis: T(n) = theta(n - i)
    for (i = 0; i< arrSize; i++) {
        minInd = findIndexOfMin(arr, i, arrSize - 1);
        swap(arr[i], arr[minInd]);
    }
}

int main() {
    int arr[13] = {5, 14, 10, 8, 13, 1, 18, 3, 4, 2, 19, 3, 4};
    int arrSize = 13;
    
    selectionSort(arr, arrSize);
    printArray(arr, arrSize);
    
    return 0;
}
