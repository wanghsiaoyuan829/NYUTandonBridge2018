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
using namespace std;

const double CALLRATE_BEFOREHOURS_WEEKDAYS = .25;
const double CALLRATE_BETWEENHOURS_WEEKDAYS = .40;
const double CALLRATE_WEEKENDS = .15;

int main() {
    
    int startCallHour, startCallMinute;
    int endCallHour, endCallMinute;
    int minutesBefore8, minutesAfter8;
    char colon;
    string dayOfTheWeek;
    string timeOfDay;
    double chargesBefore8, chargesAfter8;
    int totalMinutes, totalHours;
    double totalCallMinuteCharge;
    
    cout<<"Enter the time you started the call in 24-hour notation (e.g. 1:30 P.M. is 13:30)"<<endl;
    cin>>startCallHour>>colon>>startCallMinute;
    
    cout<<"Enter the time you ended the call in 24-hour notation (e.g. 12:30 A.M. is 00:30)"<<endl;
    cin>>endCallHour>>colon>>endCallMinute;
    
    cout<<"Enter the day of the week you started the call (e.g. If Monday, enter 'Mo'. If Friday, enter 'Fr'.)"<<endl;
    cin>>dayOfTheWeek;
    
    // Captures an edge case where a customer calls at 23:20 until 00:30. In other words, before midnight and after midnight.
    if (endCallHour < startCallHour) {
        endCallHour += 24;
        totalHours = endCallHour - startCallHour;
        totalMinutes = totalHours * 60 + (endCallMinute - startCallMinute);
    } else {
        totalHours = endCallHour - startCallHour;
        totalMinutes = totalHours * 60 + (endCallMinute - startCallMinute);
    }
    
    minutesBefore8 = (8 - startCallHour) * 60;
    minutesAfter8 = (endCallHour - 8) * 60;
    chargesBefore8 = minutesBefore8 * CALLRATE_BEFOREHOURS_WEEKDAYS;
    chargesAfter8 = minutesAfter8 * CALLRATE_BETWEENHOURS_WEEKDAYS;
    
    totalCallMinuteCharge = 0;
    
    // Captures the weekday cases
    if (dayOfTheWeek == "Mo" || dayOfTheWeek == "Tu" || dayOfTheWeek == "We" || dayOfTheWeek == "Th" || dayOfTheWeek == "Fr") {
        
        // Nested if-else for call hour cases within the weekdays
        // Calls from 08:00 to 18:00
        if (startCallHour >= 8 && endCallHour <= 18) {
            totalCallMinuteCharge = totalMinutes * CALLRATE_BETWEENHOURS_WEEKDAYS;
            
        // Calls before 08:00 charging a diff rate + calls after 08:00 with a diff rate
        } else if (startCallHour < 8 && endCallHour >= 8){
            totalCallMinuteCharge = chargesBefore8 + chargesAfter8;
            
        // Calls from 18:00 to 08:00
        } else {
            totalCallMinuteCharge = totalMinutes * CALLRATE_BEFOREHOURS_WEEKDAYS;
        }
    } else {
        // Captures the weekend cases of Sa/Su charge rates
        totalCallMinuteCharge = totalMinutes * CALLRATE_WEEKENDS;
    }
    
    // Output day of the week, total call minutes, and charges to the user. 
    cout<<"Your total call minutes starting on "<<dayOfTheWeek<<" are "<<totalMinutes<<" minutes. You are charged $"<<totalCallMinuteCharge<<"."<<endl;
    
    
    return 0;
}
