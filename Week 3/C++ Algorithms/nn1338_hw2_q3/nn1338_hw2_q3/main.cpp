//
//  main.cpp
//  nn1338_hw2_q3
//
//  Created by NomNomNam on 4/25/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Suppose John and Bill worked for some time and we want to calculate the total time both of
 them worked. Write a program that reads number of days, hours, minutes each of them
 worked, and prints the total time both of them worked together as days, hours, minutes.
 
 Hint: Try to adapt the elementary method for addition of numbers to this use.
 Your program should interact with the user exactly as it shows in the following example:
 
 Please enter the number of days John has worked: 2
 Please enter the number of hours John has worked: 12
 Please enter the number of minutes John has worked: 15
 
 Please enter the number of days Bill has worked: 3
 Please enter the number of hours Bill has worked: 15
 Please enter the number of minutes Bill has worked: 20
 
 The total time both of them worked together is: 6 days, 3 hours and 35 minutes.
 
 */

#include <iostream>
using namespace std;

int main() {
    
    int daysJohnWorked, hoursJohnWorked, minutesJohnWorked;
    int daysBillWorked, hoursBillWorked, minutesBillWorked;
    int totalDaysWorked, totalHoursWorked, totalMinutesWorked;
    int hoursRemaining, hoursCarryOver, minutesRemaining, minutesCarryOver;
    
    // Store num of days John worked
    cout<<"Please enter the number of days John has worked: ";
    cin>>daysJohnWorked;
    
    // Store num of hours John worked
    cout<<"Please enter the number of hours John has worked: ";
    cin>>hoursJohnWorked;
    
    // Store num of minutes John worked
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>minutesJohnWorked;
    
    // Breakline
    cout<<endl;
    
    // Store num of days Bill worked
    cout<<"Please enter the number of days Bill has worked: ";
    cin>>daysBillWorked;
    
    // Store num of hours Bill worked
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>hoursBillWorked;
    
    // Store num of minutes Bill worked
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>minutesBillWorked;
    
    // Breakline
    cout<<endl;
    
    // Start at the smallest unit of time and carry over values from there
    totalMinutesWorked = minutesJohnWorked + minutesBillWorked; // Add total minutes John and Bill worked
    
    // If total amount of minutes added together is 121 minutes => 2 hours and 1 minute
    minutesRemaining = totalMinutesWorked % 60; // Find the remaining minutes if the added minutes together are greater than 60 minutes because 60 minutes = 1 hour
    minutesCarryOver = totalMinutesWorked / 60; // Find how many hours gets carried over from total minutes from John and Bill
    
    totalHoursWorked = hoursJohnWorked + hoursBillWorked + minutesCarryOver; // Total hours work also include both hours work and the minutesCarryOver
    
    hoursRemaining = totalHoursWorked % 24; // Find the remaining hours leftover if the hours are carried over or not
    hoursCarryOver = totalHoursWorked / 24; // Find if any hours are carried over to days because 24 hours = 1 day
    
    totalDaysWorked = daysJohnWorked + daysBillWorked + hoursCarryOver; // Find total amount of days worked by adding days worked and hours carry over (>24)
    
    // Print out
    cout<<"The total time both of them worked together is: "<<totalDaysWorked<<" days, "<<hoursRemaining<<" hours and "<<minutesRemaining<<" minutes.";
    
    return 0;
}
