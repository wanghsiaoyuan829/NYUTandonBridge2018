//
//  main.cpp
//  Military Time To 12 Hour Time
//
//  Created by NomNomNam on 4/24/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

// Convert military time to 12 hour time

int main() {
    
    int hour24, minutes24;
    int hour12, minutes12;
    char colon;
    string periodOfDay;
    
    cout<<"Please enter a time in a 24-hour format"<<endl;
    cin>>hour24>>colon>>minutes24;
    
    minutes12 = minutes24;
    
    if (hour24 >=0 && hour24 <=11) {
        periodOfDay = "am";
        if (hour24 == 0) {
            hour12 = 12;
        }
        else {
            hour12 = hour24;
        }
    }
    else {
        periodOfDay = "pm";
        if (hour24 == 12) {
            hour12 = hour24;
        }
        else {
            hour12 = hour24 - 12;
        }
    }
        
    cout<<hour24<<colon<<minutes24<<" => "<<hour12<<colon<<minutes12<<periodOfDay<<endl;
    
    return 0;
}
