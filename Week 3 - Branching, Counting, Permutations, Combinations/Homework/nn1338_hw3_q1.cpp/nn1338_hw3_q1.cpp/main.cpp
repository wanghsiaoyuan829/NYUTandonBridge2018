//
//  main.cpp
//  nn1338_hw3_q1
//
//  Created by NomNomNam on 5/1/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:
 • Buy one get one half off promotion: the lower price item is half price.
 • If the customer is club card member, additional 10% off.
 • Tax is added.
 
 Inputs to the program include:
 • Two items’ prices
 • Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
 • Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax
 rate is 8.25%)
 
 Program displays:
 • Base price - the price before the discounts and taxes
 • Price after discounts - the price after the buy one get one half off promotion and the
 member’s discount, if applicable
 • Total price – the amount of money the customer has to pay (after tax).
 
 Your program should interact with the user exactly as it shows in the following example:
 Enter price of first item: 10
 Enter price of second item: 20
 Does customer have a club card? (Y/N): y
 Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25
 Base price: 30.0
 Price after discounts: 22.5
 Total price: 24.35625
 
 */

#include <iostream>
using namespace std;

const double CLUB_MEMBER_DISCOUNT = .1;

int main() {
    
    double firstItemPrice, secondItemPrice;
    string hasClubMemberCard;
    double taxRate, baseTotalItemPrices;
    double bogoDiscount, memberDiscountWithBogo, priceAfterAllDiscounts;
    double finalPrice;
    
    cout<<"Enter price of first item: ";
    cin>>firstItemPrice;
    
    cout<<"Enter price of second item: ";
    cin>>secondItemPrice;
    
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>hasClubMemberCard;
    
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;
    
    baseTotalItemPrices = firstItemPrice + secondItemPrice;
    
    if (firstItemPrice < secondItemPrice)
        bogoDiscount = secondItemPrice + firstItemPrice / 2;
    else if (firstItemPrice > secondItemPrice)
        bogoDiscount = firstItemPrice + secondItemPrice / 2;
    else
        bogoDiscount = firstItemPrice + secondItemPrice;
    
    memberDiscountWithBogo = bogoDiscount * CLUB_MEMBER_DISCOUNT;
    priceAfterAllDiscounts = bogoDiscount - memberDiscountWithBogo;
    
    cout<<priceAfterAllDiscounts<<" is price after discounts"<<endl;
    
    if (hasClubMemberCard == "Y" || hasClubMemberCard == "y")
        finalPrice = priceAfterAllDiscounts + priceAfterAllDiscounts * (taxRate / 100);
    else if (hasClubMemberCard == "N" || hasClubMemberCard == "n")
        finalPrice = bogoDiscount + bogoDiscount * (taxRate / 100);
    else {
        cout<<"Invalid input. Please enter 'Y' or 'N' if you have a member card."<<endl;
        return 0;
    }
    
    cout<<"Base price: "<<baseTotalItemPrices<<endl;
    
    cout<<"Price after discounts: "<<priceAfterAllDiscounts<<endl;
    
    cout<<"Total price: "<<finalPrice<<endl;
    
    return 0;
}
