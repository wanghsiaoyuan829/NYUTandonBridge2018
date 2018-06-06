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
    lowCostJump1 = jumpIt(gameBoardArr1, gameBoardArr1Size - 1, n);
    cout<<"Lowest cost by jumping through adjacent elements in the board is: "<<lowCostJump1<<endl;
    
    for (int i = 0; i < gameBoardArr2Size; i++) {
        cout<<gameBoardArr2[i]<<" ";
    }
    
    cout<<endl;
    
    // Expected output: 22
    lowCostJump2 = jumpIt(gameBoardArr2, gameBoardArr2Size - 1, n);
    cout<<"Lowest cost by jumping through adjacent elements in the board is: "<<lowCostJump2<<endl;
    
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
