//
//  main.cpp
//  nn1338_hw3_q2
//
//  Created by NomNomNam on 5/2/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that:
 • Asks the user for their name.
 • Asks the user to input their graduation year.
 • Asks the user to input the current year.
 Assume the student is in a four-year undergraduate program. Display the current status the student is in. Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.
 
 Note: If graduation year equals to current year, status is ‘Graduated’; if graduation year is four years after current year, status is ‘Freshman’, etc.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter your name: Jessica
 Please enter your graduation year: 2019
 Please enter current year: 2015
 Jessica, you are a Freshman
 
 */

#include <iostream>
using namespace std;

int main() {
    
    string firstName;
    int gradYear, currYear;
    int gradeLevel;
    string gradeStatus;
    
    // Store user input
    cout<<"Please enter your name: ";
    cin>>firstName;
    
    cout<<"Please enter your graduation year: ";
    cin>>gradYear;
    
    cout<<"Please enter current year: ";
    cin>>currYear;
    
    // Find current grade level by taking predicted graduating year minus current year
    gradeLevel = gradYear - currYear;
    
    // Control flow for Freshman, Sophmore, Junior, Senior grade status
    if (gradeLevel == 4)
        gradeStatus = "Freshman";
    else if (gradeLevel == 3)
        gradeStatus = "Sophmore";
    else if (gradeLevel == 2)
        gradeStatus = "Junior";
    else if (gradeLevel == 1)
        gradeStatus = "Senior";
    
    // Fix control flow to be grammatically correct
    else if (gradeLevel <= 0) {
        gradeStatus = "graduated";
        cout<<firstName<<", you have "<<gradeStatus<<endl;
        return 0;
    } else {
        gradeStatus = "not in college yet";
        cout<<firstName<<", you are "<<gradeStatus<<endl;
        return 0;
    }
    
    // Output result of grade status to the user
    cout<<firstName<<", you are a "<<gradeStatus<<endl;
    
    return 0;
}
