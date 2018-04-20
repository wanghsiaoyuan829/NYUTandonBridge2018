//
//  main.cpp
//  upperCase
//
//  Created by NomNomNam on 4/18/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

/* Take user input of a lower case letter and convert it to it's corresponding upper case letter*/
int main()
{
    char lowerCaseLetter, upperCaseLetter;
    int offset;
    
    cout<<"Please enter a lower case letter"<<endl;
    cin>>lowerCaseLetter;
    
    offset = (int)(lowerCaseLetter - 'a');
    upperCaseLetter = (char)(offset + 'A');
    
    cout<<"The upper case letter of "<<lowerCaseLetter<<" is "<<upperCaseLetter;
    
    return 0;
}
