//
//  area_of_circle.cpp
//  Week 2 CPP
//
//  Created by NomNomNam on 4/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

const double PI = 3.14;
int main()
{
    double radius, area;
    
    cout<<"Please enter the radius:"<<endl;
    cin>>radius;
    
    area = PI * (radius*radius);
    
    cout<<"The area of a circle with radius of "<<radius<<" is "<<area<<endl;
    
    return 0;
}
