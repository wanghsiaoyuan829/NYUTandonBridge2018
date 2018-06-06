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

int jumpIt(int gameBoardArr[], int gameBoardArrSize, int n);

int main() {
    int lowCostJump1;
    int gameBoardArr1[] = {0, 3, 80, 6, 57, 10};
    int gameBoardArr1Size = 6;
    
    int lowCostJump2;
    int gameBoardArr2[] = {0, 10, 90, 5, 1, 50, 7};
    int gameBoardArr2Size = 7;
    
    int n = 0;
    
    for (int i = 0; i < gameBoardArr1Size; i++) {
        cout<<gameBoardArr1[i]<<" ";
    }
    
    cout<<endl;
    
    // Expected output: 19
    // 3 + 6 + 10
    lowCostJump1 = jumpIt(gameBoardArr1, gameBoardArr1Size - 1, n);
    cout<<"Lowest cost by jumping through 1 or 2 adjacent elements in the board is: "<<lowCostJump1<<endl;
    
    for (int i = 0; i < gameBoardArr2Size; i++) {
        cout<<gameBoardArr2[i]<<" ";
    }
    
    cout<<endl;
    
    // Expected output: 22
    // 10 + 5 + 7
    lowCostJump2 = jumpIt(gameBoardArr2, gameBoardArr2Size - 1, n);
    cout<<"Lowest cost by jumping through 1 or 2 adjacent elements in the board is: "<<lowCostJump2<<endl;
    
    return 0;
}

// Input: game board array, array size, and index position to compare elements
// Output: return the lowest cost value by jumping through adjacent elements in the array
int jumpIt(int gameBoardArr[], int gameBoardArrSize, int n) {
    // Base case #1: if current index position is equal to gameBoardArrSize
    if (n == gameBoardArrSize) {
        return gameBoardArr[n];
    // Base case #2: if there are only the first and last element in the array
    // return the sum of the first element and the last element
    } else if (n == gameBoardArrSize - 1) {
        return (gameBoardArr[0] + gameBoardArr[gameBoardArrSize]);
    // Recursive function: if the previous element is less than the next element
    // return the sum of the current index to the value of the next element
    } else if (jumpIt(gameBoardArr, gameBoardArrSize, n + 1) < jumpIt(gameBoardArr, gameBoardArrSize, n + 2))
        return (gameBoardArr[n] + jumpIt(gameBoardArr, gameBoardArrSize, n + 1));
    // Recursive function: else the previous element is NOT less than the next element
    // Jump two indexes and add the value of that index to the current value of the current element
    else
        return (gameBoardArr[n] + jumpIt(gameBoardArr, gameBoardArrSize, n + 2));
}
