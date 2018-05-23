//
//  main.cpp
//  above average
//
//  Created by NomNomNam on 5/22/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX_CLASS_SIZE = 5;
double calcArrAvg(int arr[], int arrSize);
void printAboveValue(int arr[], int arrSize, double value);
int readArr(int arr[], int physicalSize);

int main() {
    int gradesArr[MAX_CLASS_SIZE];
    int gradesArrSize;
    double averageGrade;
    
    // read data
    gradesArrSize = readArr(gradesArr, MAX_CLASS_SIZE);
    
    // calcukate average
    averageGrade = calcArrAvg(gradesArr, gradesArrSize);
    cout<<"The average is: "<<averageGrade<<endl;
    
    // print values above the average
    printAboveValue(gradesArr, gradesArrSize, averageGrade);
    
    return 0;
}

double calcArrAvg(int arr[], int arrSize){
    int i, sum;
    double average;
    
    sum = 0;
    for (i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    average = (double)sum / (double)arrSize;
    return average;
}

void printAboveValue(int arr[], int arrSize, double value){
    int i;
    
    cout<<"The values above "<<value<<" are: ";
    for (i = 0; i < arrSize; i++) {
        if(arr[i] > value)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int readArr(int arr[], int physicalSize){
    int arrSize;
    int i;
    
    cout<<"Please enter the number of values (no more than "<<physicalSize<<")"<<endl;
    cin>>arrSize;
    
    cout<<"Enter the values, separated by a space: "<<endl;
    for(i = 0; i < arrSize; i++)
        cin>>arr[i];
    
    return arrSize;
}
