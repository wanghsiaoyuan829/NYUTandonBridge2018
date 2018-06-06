//
//  nn1338_hw8_q4.cpp
//  nn1338_hw8_q4
//
//  Created by NomNomNam on 6/5/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 The game of “Jump It” consists of a board with n positive integers in a row, except for the first
 column, which always contains zero. These numbers represent the cost to enter each column.
 Here is a sample game board where n is 6:
    0  3   80  6   57  10
 
 The object of the game is to move from the first column to the last column with the lowest total
 cost.
 The number in each column represents the cost to enter that column. You always start the game
 in the first column and have two types of moves. You can either move to the adjacent column or
 jump over the adjacent column to land two columns over. The cost of a game is the sum of the
 costs of the visited columns.
 In the board shown above, there are several ways to get to the end. Starting in the first column,
 our cost so far is 0. We could jump to 80, then jump to 57, and then move to 10 for a total cost
 of 80 + 57 + 10 = 147. However, a cheaper path would be to move to 3, jump to 6, then jump to
 10, for a total cost of 3 + 6 + 10 = 19.
 Write a recursive function that solves this problem and returns the lowest cost of a game board
 represented and passed as an array.
 Note: your function shouldn’t output the actual sequence of jumps, only the lowest cost of this
 sequence.
 
 */

#include <iostream>
using namespace std;

int main() {
    
    return 0;
}
