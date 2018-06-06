//
//  main.cpp
//  printAsc
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

void printAsc(int start, int end);

int main() {
    int start = 1;
    int end = 10;
    
    printAsc(start, end);
    
    return 0;
}

void printAsc(int start, int end) {
    if (start == end) {
        cout<<start<<endl;
    }
    else {
        printAsc(start, end - 1);
        cout<<end<<endl;
    }
}
