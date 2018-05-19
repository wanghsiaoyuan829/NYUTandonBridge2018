//
//  main.cpp
//  nn1338_hw5_q3
//
//  Created by NomNomNam on 5/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
a. Implement a function:
 int printMonthCalender(int numOfDays, int startingDay)
 This function is given two parameters:
    • numOfDays - The number of days in the month
    • startingDay – a number 1-7 that represents the day in the week of the first day
        in that month (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).
 
 The function should:
    Print a formatted monthly calendar of that month
    Return a number 1-7 that represents the day in the week of the last day in that
    month.
 
 Formatting Notes:
 The output should include a header line with the days’ names.
 Columns should be spaced by a Tab.
 
 Example: when calling printMonthCalender(31, 4) it should return 6, and should
 print:
 Mon Tue Wed Thr Fri Sat Sun
              1   2   3   4
  5   6   7   8   9   10  11
  12  13  14  15  16  17  18
  19  20  21  22  23  24  25
  26  27  28  29  30  31
 
 b. A method for determining if a year is a leap year in the Gregorian calendar system is to
    check if it is divisible by 4 but not by 100, unless it is also divisible by 400.
    For example, 1896, 1904, and 2000 were leap years but 1900 was not.
    Write a function that takes in a year as input and return true if the year is a leap year, return false otherwise.
    Note: background on leap year https://en.wikipedia.org/wiki/Leap_year
 
 c. Implement a function:
    void printYearCalender(int year, int startingDay)
    This function is given two parameters:
    • year – an integer that represents a year (e.g. 2016)
    • startingDay – a number 1-7 that represents the day in the week of 1/1 in that
        year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).
 
    The function should use the functions from sections (a) and (b) in order to print a
    formatted yearly calendar of that year.
 
    Formatting Note: As the header for each month you should print the months’ name
    followed by the year (e.g. March 2016).
 
    Example: Appendix A shows the expected output of the call
    printYearCalender(2016, 5).
 
 d. Write program that interacts with the user and your function in (c).
 
 */

#include <iostream>
using namespace std;


int printMonthCalender(int numOfDays, int startingDay);
//int checkLeapYear(int year);
//void printYearCalender(int year, int startingDay);

int main() {
    
    int numOfDays, startingDay;
    
    //cout<<"section a"<<endl;
    cout<<"Please enter number of days in the month: ";
    cin>>numOfDays;
    
    cout<<"Please enter the starting day of the month (e.g. 4 is the first Sunday of the calendar month): ";
    cin>>startingDay;
    
    printMonthCalender(numOfDays, startingDay);
    //cout<<"section b"<<endl;
    
    //cout<<"section c"<<endl;
    
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    
    int lastDay;
    int week, day;
    // lastDay = 6 (Saturday)
    // numOfDays = 31
    // startingDay = 4 (Sunday)
    
    lastDay = numOfDays;
    for (week = 1; week <= (numOfDays / 7); week++) {
        for (day = 1; day <= (numOfDays / 7); day++) {
            cout<<day<<'\t';
        }
        // New week line
        cout<<endl;
    }
    return lastDay;
}


//int checkLeapYear(int year) {
//    bool isLeapYear;
//
//
//    return isLeapYear;
//}
//
//void printYearCalender(int year, int startingDay) {
//
//}
