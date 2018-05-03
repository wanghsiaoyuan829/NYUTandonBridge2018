//
//  main.cpp
//  playground
//
//  Created by NomNomNam on 5/2/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const double POUND_TO_KILOGRAM = 0.453592;
const double INCH_TO_METER = 0.0254;

int main() {
    
    double weightInPounds, heightInInches;
    double bmiValue;
    string weightStatus;
    
    cout<<"Please enter weight (in pounds): ";
    cin>>weightInPounds;
    
    cout<<"Please enter height (in inches): ";
    cin>>heightInInches;
    
    bmiValue = (weightInPounds * POUND_TO_KILOGRAM) / exp((heightInInches * INCH_TO_METER));
    
//    cout<<bmiValue<<endl;
    cout<<22.6796 / (1.778 * 1.778)<<endl;
    return 0;
}
