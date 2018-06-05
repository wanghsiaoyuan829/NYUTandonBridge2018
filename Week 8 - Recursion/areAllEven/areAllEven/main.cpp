//
//  main.cpp
//  areAllEven
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

bool areAllEven(int arr[], int n);

int main() {
    int arr[4] = {2, 26, 42, 14};
    
    if (areAllEven(arr, 4) == true)
        cout<<"All are even"<<endl;
    else
        cout<<"All are NOT even"<<endl;
    
    return 0;
}

bool areAllEven(int arr[], int n) {
    bool res;
    
    if (n == 1)
        return (arr[0] % 2 == 0);
    else {
        res = areAllEven(arr, n-1);
        if (res == true)
            return (arr[n-1] % 2 == 0);
        else
            return false;
    }
}
