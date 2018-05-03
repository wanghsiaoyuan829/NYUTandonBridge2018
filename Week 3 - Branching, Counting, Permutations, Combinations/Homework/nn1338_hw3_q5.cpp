//
//  main.cpp
//  nn1338_hw3_q4
//
//  Created by NomNomNam on 5/3/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

//
//  main.cpp
//  nn1338_hw3_q5
//
//  Created by NomNomNam on 5/3/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Body mass index (BMI) is a number calculated from a person’s weight and height using the following formula: 𝑤𝑒𝑖𝑔h𝑡/h𝑒𝑖𝑔h𝑡#. Where 𝑤𝑒𝑖𝑔h𝑡 is in kilograms and h𝑒𝑖𝑔h𝑡 is in meters.
 
 According to the Centers for Disease Control and Prevention, the BMI is a fairly reliable indicator of body fatness for most people. BMI does not measure body fat directly, but research has shown that BMI correlates to direct measures of body fat, such as underwater weighing and dual-energy X-ray absorptiometry.
 
 The following table gives the weight status in respect to the BMI value:
    BMI Range      Weight Status
    Below 18.5     Underweight
    [18.5, 25)     Normal
    [25, 30)       Overweight
    30 and above   Obese
 
 Write a program that prompts for weight (in pounds) and height (in inches) of a person, and prints the weight status of that person.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter weight (in pounds): 135
 Please enter height (in inches): 71
 The weight status is: Normal
 
 Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.
 
 */

#include <iostream>
#include <cmath>

using namespace std;

const double POUND_TO_KILOGRAM = 0.453592;
const double INCH_TO_METER = 0.0254;

int main() {
    
    double weightInPounds, heightInInches;
    double convertedPoundsToKilogram, convertedInchesToMeter;
    double bmiValue;
    string weightStatus;
    
    cout<<"Please enter weight (in pounds): ";
    cin>>weightInPounds;
    
    cout<<"Please enter height (in inches): ";
    cin>>heightInInches;

    // Conversion of units
    convertedPoundsToKilogram = weightInPounds * POUND_TO_KILOGRAM;
    convertedInchesToMeter = heightInInches * INCH_TO_METER;
    
    // Formula for BMI is weight in KG / height in meter squared
    bmiValue = convertedPoundsToKilogram / pow(convertedInchesToMeter, 2);

    // Ranges of weight status for BMI ranges
    if (bmiValue < 18.5)
        weightStatus = "Underweight";
    else if (bmiValue < 25)
        weightStatus = "Normal";
    else if (bmiValue < 30)
        weightStatus = "Overweight";
    else
        weightStatus = "Obese";
    
    cout<<"The weight status is: "<<weightStatus<<endl;
    
    return 0;
}
