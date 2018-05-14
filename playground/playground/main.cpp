//
//  main.cpp
//  playground
//
//  Created by NomNomNam on 5/2/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    float price;
    price = 10;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "The price is $" << 5/price << endl;
    
    return 0;
}
