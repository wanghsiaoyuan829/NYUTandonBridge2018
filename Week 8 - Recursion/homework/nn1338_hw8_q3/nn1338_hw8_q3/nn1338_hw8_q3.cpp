//
//  main.cpp
//  nn1338_hw8_q3
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write two recursive versions of the function minInArray. The function will be given a
 sequence of elements and should return the minimum value in that sequence.
 The two versions differ from one another in the technique we use to pass the sequence to the function.
 
 In version 1 - The prototype of the function should be:
 int minInArray1(int arr[], int arrSize)
 Here, the function is given arr, an array of integers, and its logical size, arrSize.
 The function should find the minimum value out of all the elements in positions:
 0, 1, 2, ..., arrSize-1.
 
 In version 2 – The prototype of the function should be:
 int minInArray2(int arr[], int low, int high)
 Here, the function is given arr, an array of integers, and two additional indices: low and high
 (low <= high), which indicate the range of indices that need to be considered.
 The function should find the minimum value out of all the elements in positions:
 low, low+1, ..., high.
 
 Use the following main to check your program:
 int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
 
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<” “<<res2<<endl; //should both be -9
 
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<” “<<res4<<endl; //should both be 3
 
 return 0;
 
 }
 
 */

#include <iostream>
using namespace std;

int main() {
    
    return 0;
}
