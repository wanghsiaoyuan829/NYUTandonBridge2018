//
//  main.cpp
//  Week 2 CPP
//
//  Created by NomNomNam on 4/16/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/* This program reads two integers from the user and prints their sum */

#include <iostream>
using namespace std;

int main()
{
    int num1; // will hold the first input
    int num2; // will hold the second input
    int sum;  // will hold the sum
    
    cout<<"Please enter two numbers separated by a space:"<<endl;
    cin>>num1>>num2;
    
    sum = num1 + num2;
    
    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    
    return 0;
}
