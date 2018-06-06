//
//  main.cpp
//  printAscAndDec
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

void printAscAndDesc(int start, int end);

int main() {
    int start = 1;
    int end = 10;
    
    printAscAndDesc(start, end);
    
    return 0;
}

void printAscAndDesc(int start, int end) {
    if (start == end) {
        cout<<start<<endl;
    }
    else {
        cout<<start<<endl;
        printAscAndDesc(start + 1, end);
        cout<<start<<endl;
    }
}
