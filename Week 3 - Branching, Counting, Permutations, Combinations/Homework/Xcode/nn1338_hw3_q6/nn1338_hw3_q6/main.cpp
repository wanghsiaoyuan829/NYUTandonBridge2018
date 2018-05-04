//
//  main.cpp
//  nn1338_hw3_q6
//
//  Created by NomNomNam on 5/3/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that computes the cost of a long-distance call. The cost of   the call is determined according to the following rate schedule:
 • Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a
 rate of $0.40 per minute.  
 • Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged
 at a rate of $0.25 per minute.  
 • Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.   The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
 The output will be the cost of the call.
 Notes:
 1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as   13:30  
 2. The day of the week will be read as one of the following two character string: Mo Tu
 We Th Fr Sa Su
 3. The number of minutes will be input as a positive integer.
 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int startCallHour, startCallMinute;
    int endCallHour, endCallMinute;
    char colon;
    string dayOfTheWeek;
    string timeOfDay;
    double callRateBetweenHoursWeekday, callRateBeforeHoursWeekday;
    double callRateWeekend;
    int totalMinutes, totalHours;
    double totalCallMinuteCharge;
    
    cout<<"Enter the time you started the call in 24-hour notation (e.g. 1:30 P.M. is 13:30)"<<endl;
    cin>>startCallHour>>colon>>startCallMinute;
    
    cout<<"Enter the time you ended the call in 24-hour notation (e.g. 12:30 A.M. is 00:30)"<<endl;
    cin>>endCallHour>>colon>>endCallMinute;
    
    cout<<"Enter the day of the week you started the call (e.g. If Monday, enter 'Mo'. If Friday, enter 'Fr'.)"<<endl;
    cin>>dayOfTheWeek;
    
    // Charge Rates for certain days of the week and time of the week
    callRateBeforeHoursWeekday = .25;
    callRateBetweenHoursWeekday = .40;
    callRateWeekend = .15;

    totalHours = endCallHour - startCallHour;
    totalMinutes = totalHours * 60 + (endCallMinute - startCallMinute);
    totalCallMinuteCharge = 0;
    
    // nested if else statement
    if (dayOfTheWeek == "Mo" || dayOfTheWeek == "Tu" || dayOfTheWeek == "We" || dayOfTheWeek == "Th" || dayOfTheWeek == "Fr") {
        if (startCallHour >= 8 && endCallHour <= 18) {
            totalCallMinuteCharge = totalMinutes * .40;
        } else {
            // endCallHour = endCallHour + 24;
            totalCallMinuteCharge = totalMinutes * .25;
        }
    } else {
        totalCallMinuteCharge = totalMinutes * .15;
    }
    
    cout<<"Your total call minutes starting on "<<dayOfTheWeek<<" are "<<totalMinutes<<" . You are charged "<<totalCallMinuteCharge<<endl;
    
    
    return 0;
}
