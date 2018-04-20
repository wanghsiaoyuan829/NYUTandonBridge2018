//
//  main.cpp
//  AreaOfCircle
//
//  Created by NomNomNam on 4/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double radius, area;
    
    cout<<"Please enter the radius:"<<endl;
    cin>>radius;
    
    area = M_PI * (radius*radius);
    
    cout<<"The area of a circle with radius of "<<radius<<" is "<<area<<endl;
    
    return 0;
}
