//
//  main.cpp
//  cosine function
//
//  Created by NomNomNam on 5/16/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

double cos(double x, int n);
double power(double base, int exp);
double factorial(int n);

int main() {
    double res;
    
    cout.precision(30);
    
    for (int i = 1; i <= 10; i++) {
        res = cos(1, i);
        cout<<res<<endl;
    }
    return 0;
}

double cos(double x, int n) {
    double sum;
    double currTerm;
    int count, sign;
    
    sum = 0;
    
    for (count = 0, sign = 1; count <= (n-1); count++, sign *= -1) {
        currTerm = power(x, 2*count) / factorial(2*count);
        sum += currTerm;
    }
    return sum;
}

// assume exp >= 0
double power (double base, int n) {
    double res;
    int count;
    
    res = 1;
    for (count = 1; count <= n; count++) {
        res *= base;
    }
    return res;
}

// assume n >= 0
double factorial(int n) {
    double res;
    int count;
    
    res = 1;
    for (count = 1; count <= n; count++) {
        res *= count;
    }
    return res;
}
