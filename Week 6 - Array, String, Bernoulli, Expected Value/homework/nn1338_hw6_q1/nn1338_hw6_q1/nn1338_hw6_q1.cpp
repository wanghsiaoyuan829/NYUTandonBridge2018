//
//  main.cpp
//  nn1338_hw6_q1
//
//  Created by NomNomNam on 5/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Part 1:
 Implement the function: int minInArray(int arr[], int arrSize)
 This function is given arr, an array of integers, and its logical size, arrSize. When called,
 it returns the minimum value in arr.
 
 Part 2:
 Write a program that reads from the user a sequence of 20 integers (unnecessarily different
 from one another) into an array, and outputs the minimum value, and all the indices it
 appears in the array.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter 20 integers separated by a space:
 14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6
 The minimum value is 5, and it is located in the following indices: 1 3 6 14
 
 Note: You may want to define additional functions for your program to use.
 
*/

#include<iostream>
using namespace std;

/* Part 1 ~~~~~~~~~~~~~~~~~~~~~
int minInArray(int arr[],int n);

int main() {
    
    int num, min;
    
    //Input from the user is saved into array size
    cout<<"Please enter the array size: \n";
    cin>>num;
    int arr[num], i;

    //Input from the user is saved into elements of the array
    cout<<"Enter the elements of the array: \n";
    for(i = 0; i < num; i++) {
        cin>>arr[i];
    }
    
    //Output elements in the array back to user
    cout<<"Your array elements are: ";
    for(i = 0; i < num; i++)
        cout<<arr[i]<<" ";
    
    //Calling the minInArray() function
    min = minInArray(arr, num);
    
    //Output the minimum integer element in the array
    cout <<"\nThe minimum value in your array is: "<<min<<endl;
    
    return 0;
}

//minInArray function
//Input: two parameters - 1) array 2) integer
//Output: minimum integer in the array
int minInArray(int arr[],int num){
    int i, min = 999999;
    //Iterate through each element of the array
    for(i = 0; i < num; i++){
        //Finding the new minimum integer value
        if(arr[i] < min)
            min = arr[i];
    }
    
    return min;
}

END OF PART 1
*/

int minInArray(int arr[],int num);
void minIndex(int arr[],int num);

int main() {
    
    //Fixed user input to 20 elements in an array
    int num = 20;
    int arr[num], i;
    
    //Input from the user is saved into each element in the array
    cout<<"Please enter 20 integers separated by a space:\n";
    for (i = 0; i < num; i++) {
        cin>>arr[i];
    }
    
    //Output the minimum integer element in the array & index of where the minimum value is located in the array
    minIndex(arr, num);
    
    return 0;
}

//minInArray function
//Input: two parameters - 1) array 2) integer
//Output: minimum integer in the array
int minInArray(int arr[],int num){
    int i, min = 999999;
    //Iterate through each element of the array
    for(i = 0; i < num; i++){
        //Finding the new minimum integer value
        if(arr[i] < min)
            min = arr[i];
    }
    
    return min;
}

void minIndex(int arr[],int num) {
    
    int min;
    
    //Calling the minInArray() function
    min = minInArray(arr, num);
    
    //Output the minimum integer element in the array
    cout <<"The minimum value is "<<min<<", and it is located in the following indices: ";
    
    //Output the index of where the minimum value is located in the array
    for (int i = 0; i < num; i++) {
        if (arr[i] == min)
            cout<<i<<" ";
    }
    
    cout<<endl;
}
