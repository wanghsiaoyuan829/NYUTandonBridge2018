//
//  main.cpp
//  factorial
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

int factorial(int n);

int main() {
    
    cout<<factorial(5)<<endl;
    
    return 0;
}

int factorial(int n) {
    int res;
    
    if (n == 1) {
        return 1;
    }
    else {
        res = factorial(n-1);
        res *= n;
        return res;
    }
}
