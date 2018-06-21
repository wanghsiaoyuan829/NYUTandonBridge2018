//
//  main.cpp
//  merge_sort
//
//  Created by NomNomNam on 6/20/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

// Runtime Analysis: T(n) = n(log(n))
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize) {
    int i;
    
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void merge(int arr[], int lowLeft, int highLeft, int highRight) {
    int lowRight, size;
    int* mergedArr;
    int iRight, iLeft, iRes;
    int i, iArr;
    
    lowRight = highLeft + 1;
    size = highRight - lowLeft + 1;
    mergedArr = new int[size];
    
    iLeft = lowLeft;
    iRight = lowRight;
    iRes = 0;
    
    while (iLeft <= highLeft && iRight <= highRight) {
        if (arr[iLeft] < arr[iRight]) {
            mergedArr[iRes] = arr[iLeft];
            iLeft++;
            iRes++;
        } else {
            mergedArr[iRes] = arr[iRight];
            iRight++;
            iRes++;
        }
    }
    
    while (iLeft <= highLeft) {
        mergedArr[iRes] = arr[iLeft];
        iLeft++;
        iRes++;
    }
    
    while (iRight <= highRight) {
        mergedArr[iRes] = arr[iRight];
        iRight++;
        iRes++;
    }
    
    for (i = 0, iArr = lowLeft; i < size; i++, iArr++)
        arr[iArr] = mergedArr[i];
    
    delete [] mergedArr;
}

void mergeSort(int arr[], int low, int high){
    int mid;
    
    if (low == high) {
        return;
    } else {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[8] = {14, 5, 8, 10, 13, 1, 18, 3};
    int arrSize = 8;
    
    mergeSort(arr, 0, arrSize - 1);
    printArray(arr, arrSize);
    
    return 0;
}
