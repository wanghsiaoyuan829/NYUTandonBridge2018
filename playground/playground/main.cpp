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
    
    int correctNum;
    
    srand(time(0));
    
    correctNum = rand() % 100 + 1;
    
    cout<<correctNum<<endl;
    
    return 0;
}
