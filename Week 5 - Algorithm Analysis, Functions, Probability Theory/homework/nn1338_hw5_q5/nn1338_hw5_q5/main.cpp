//
//  main.cpp
//  nn1338_hw5_q5
//
//  Created by NomNomNam on 5/17/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Consider the following definitions:
 a. A proper divisors of a positive integer (≥ 2) is any of its divisors excluding the number itself.
 For example, the proper divisors of 10 are: 1, 2 and 5.
 b. A perfect number is a positive integer (≥ 2) that is equal to the sum of its proper divisors.
 For example, 6 and 28 are perfect numbers, since:
 6 = 1 + 2 + 3
 28 = 1 + 2 + 4 + 7 + 14
 Background of perfect numbers: https://en.wikipedia.org/wiki/Perfect_number
 c. Amicable numbers are two different positive integer (≥ 2), so related that the sum of the proper divisors of each is equal to the other number.
 For example, 220 and 284 are amicable numbers, since:
 284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110
 
 220 = 1 + 2 + 4 + 71 + 142
 (proper divisors of 220)
 (proper divisors of 284)
 Background of amicable numbers: https://en.wikipedia.org/wiki/Amicable_numbers
 
 a. Write a function:
 void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) The function takes as an input a positive integer num (≥ 2), and updates two output parameters with the number of num's proper divisors and their sum.
 For example, if this function is called with num=12, since 1, 2, 3, 4 and 6 are 12s proper divisors, the function would update the output parameters with the numbers 5 and 16. Note: Pay attention to the running time of your function. An efficient implementationw ould run in 0(num^1/2).
 
 b. Use the function you wrote in section (a), to implement the function:
 bool isPerfect(int num)
 This functions is given positive integer num (≥ 2), and determines if it is perfect number or not.
 
 c. Use the functions you implemented in sections (a) and (b), to write a program that reads from the user a positive integer M (≥ 2), and prints:
 • All the perfect numbers between 2 and M.
 • All pairs of amicable numbers that are between 2 and M (both numbers must be in the
 range).
 Note: An efficient algorithm for this part would call analyzeDividors 0(M) times all together.
 
*/

#include<iostream>
#include<cmath>

using namespace std;

void analyzeDividors(int num, int *outCountDivs, int outSumDivs[]);
bool isPerfect(int num);
int getSum(int num);
void findAmicable(int num);

int main() {
    
    int n;
    
    cout<<"Enter a positive integer >= 2: ";
    cin>>n;
    
    cout<<"amicable pairs are ...\n";
    findAmicable(n);
    
    return 0;
}

void analyzeDividors(int num, int *outCountDivs, int outSumDivs[]) {
    
    int j;
    
    for (j = 1 ; j <= sqrt(num) + 1 ; j++) {
        if (num % j == 0) {
            if (num / j == j)
                outSumDivs[(*outCountDivs)++] = j;
            else {
                outSumDivs[(*outCountDivs)++] = j;
                outSumDivs[(*outCountDivs)++] = num / j;
            }
        }
    }
}

bool isPerfect(int num) {
    
    int x=1, sum=0;
    
    while(x < num) {
        if(num % x == 0)
            sum = sum + x;
        x++;
    }
    
    if(sum == num)
        return true;
    return false;
    
}

int getSum(int num) {
    
    int x=1, sum=0;
    
    while(x < num) {
        if(num % x == 0)
            sum = sum + x;
        x++;
    }
    
    return sum;
}

void findAmicable(int num) {
    
    int i, j, arr[num + 1];
    
    arr[0] = -1;
    arr[1] = -1;
    
    cout<<"Perfect Numbers are ...\n";
    
    for( i = 2 ; i < num ; i++) {
        if(isPerfect(i))
            cout<<i<<" ";
        
        arr[i] = getSum(i);
    }
    
    cout<<endl;
    
    for (i = 2; i < num; i++)
        for (j = i + 1; j<num; j++)
            if(arr[i] == arr[j])
                cout<<i<<" - "<<j<<endl;
}

