#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    // Use fixed variables to test function
    int arr[] = {3, 1, 3, 0, 6, 4};
    int resArrSize;
    
    // Calling function findMissing and storing the return base value of the
    // resArray to the new missingNumArray variable
    int* missingNumArray = findMissing(arr, 6, resArrSize);
    
    // Iterate missingNumArray up to new resArrSize
    // Print to user the elements in the array
    for(int i=0; i<resArrSize; i++)
        cout<<missingNumArray[i]<<" ";
    
    cout<<endl;
    
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    
    resArrSize = n; // Store current resArrSize to original n size elements
    // Initialize new dynamic arrays
    int* tempArr = new int[n];
    int* resArray = new int[resArrSize];
    
    // tempArr = [1, 2, 3, 4, 5, 6]
    for(int i = 0; i < n; i++) {
        tempArr[i] = i + 1;
    }
    
    // Implement finding n + 1 missing num logic
    for(int i = 0; i < n; i++) {
        if(tempArr[arr[i] - 1] == arr[i]) {
            // Set tempArr elements to -1
            tempArr[arr[i] - 1] = -1;
            // Resize resArrSize subtracted from n size based on missing num elements
            resArrSize--;
        }
    }
    
    int missingNumCounter = 0;
    
    for(int i = 0; i < n; i++) {
        // iterate through the new tempArr elements and find which one
        // is greater than 0
        if(tempArr[i] > 0) {
            // store tempArr to the resArray
            // Increment the missingNumCounter based on how many elements
            // is in tempArr
            resArray[missingNumCounter] = tempArr[i];
            missingNumCounter++;
        }
    }
    
    // Update new resArrSize based on the counter of missing nums (n + 1)
    resArrSize = missingNumCounter;
    
    // Return base value of array
    return resArray;
}
