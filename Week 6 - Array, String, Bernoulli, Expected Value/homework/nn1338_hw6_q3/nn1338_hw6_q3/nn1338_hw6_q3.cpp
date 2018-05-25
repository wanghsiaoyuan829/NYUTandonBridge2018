//
//  nn1338_hw6_q3.cpp
//  nn1338_hw6_q3
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Implement following functions:
 a. void reverseArray(int arr[], int arrSize)
    That takes arr, an array of integers, and its size, arrSize. When called, it reorders the
    elements of the array to appear in a reverse order.
    For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray,arr
    will look like: [4, 3, 2, 1].
 
 b. void removeOdd(int arr[], int& arrSize)
    That takes arr, an array of integers, and its size, arrSize. When called, the function
    alters arr so that the only numbers in it at the end are the even ones, which should remain
    in their original relative order.
    Additionally, the function updates arrSize so it contains the new logical size of the array
    after removing the odd numbers (note that arrSize is a parameter used both for input
    and output).
    For example, if arr is an array containing [1, 2, 3, 4], after calling removeOdd, arr will
    look like: [2, 4], and the parameter arrSize will update to 2. Notice the values in arr[2]
    and arr[3] are discarded.
 
 c. void splitParity(int arr[], int arrSize)
    That takes arr, an array of integers, and its size, arrSize. When called, the function
    changes the order of numbers in arr so that all the odd numbers will appear first, and all
    the even numbers will appear last. Note that the inner order of the odd numbers and the
    inner order of the even numbers don’t matter.
    For example, if arr is an array containing [1, 2, 3, 4], after calling splitParity, arr could look
    like: [3, 1, 2, 4].
 
 Implementation requirements:
 1. In all three functions, you are not allowed to use an auxiliary array (a temporary local array).
 2. Pay attention to the running time of your functions. For each one of the functions above, an
 efficient implementation would run in a linear time (that is Θ 𝑎𝑟𝑟𝑆𝑖𝑧𝑒 ).
 
 Note: You don’t have to submit a main function for this question. You may use the following
 program to test your functions:
 
 #include <iostream>
 using namespace std;
 
 void printArray(int arr[], int arrSize);
 
 int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
 
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
 
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
 
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
 
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
 
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
 
    return 0;
 }

 void printArray(int arr[], int arrSize){
    int i;
 
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
 }

 When running this program you should expect the following output (the output for
 splitParity could be different):
 -3 12 14 2 9
 12 6 14
 1 3 6 4 12
 
 */

#include <iostream>
using namespace std;

// Section A
void reverseArray(int arr[], int arrSize);
// Section B
void removeOdd(int arr[], int& arrSize);
// Section C
void splitParity(int arr[], int arrSize);
//void removeDuplicates(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    
    // 3 Prebuilt input to test output of three different functions
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    cout<<"\nSection A: Reversed array\n";
    printArray(arr1, arr1Size);
    cout<<"reversed is \n";
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    cout<<"\nSection B: Removed Odds\n";
    printArray(arr2, arr2Size);
    cout<<"removed odds is \n";
    removeOdd(arr2, arr2Size);
    cout<<endl;
    
    cout<<"\nSection C: Split Parity\n";
    printArray(arr3, arr3Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    
    return 0;
    
}

// Reverse elements of array
// Input: array and size of array
// Output: all elements in the array is reversed
void reverseArray(int arr[], int arrSize) {
    int first, n;
    int last = arrSize - 1; // Get last element of array
    
    for (first = 0; first < (arrSize - 1) / 2; first++, last--) {
        n = arr[first];
        arr[first] = arr[last];
        arr[last] = n;
    }
}

// Remove odd elements and keep only the even elements
// Updates array size
// Input: array and size of array
// Output: even elements in an array
void removeOdd(int arr[], int& arrSize) {
    int newSize = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            cout<<arr[i]<<" ";
            newSize++;
        }
    }
    arrSize = newSize;
}

// Split the array, the first half of the array,
// the elements are odds and the second half is evens
// Input: array and size of array
// Output: odds and evens element are split within an array
void splitParity(int arr[], int arrSize) {
    
    int first, n;
    int last = arrSize - 1;

    for (first = 0; first < (arrSize - 1) / 2; first++, last--) {
        if (arr[first] % 2 == 0) {
            n = arr[first];
            arr[first] = arr[last];
            arr[last] = n;
        }
    }
}

// Iterate an array and print out all the elements within an array
void printArray(int arr[], int arrSize) {
    
    int i;
    
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
