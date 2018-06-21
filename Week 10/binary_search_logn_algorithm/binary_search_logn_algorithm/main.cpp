//
//  main.cpp
//  binary_search_logn_algorithm
//
//  Created by NomNomNam on 6/20/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

#include <iostream>
using namespace std;

int sortedSearch(int srtArr[], int srtArrSize, int val);

int main() {
    int srtArr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    cout<<sortedSearch(srtArr, 10, 13)<<endl;
    cout<<sortedSearch(srtArr, 10, 14)<<endl;
    
    return 0;
}

int sortedSearch(int srtArr[], int srtArrSize, int val) {
    int low, high, mid;
    int ind;
    bool found;
    
    low = 0;
    
    high = srtArrSize - 1;
    found = false;
    while ((found == false) && (low <= high)) {
        mid = (low + high) / 2;
        if (srtArr[mid] == val) {
            ind = mid;
            found = true;
        }
        else if (val < srtArr[mid])
            high = mid - 1;
        else // val > srtArr[mid]
            low = mid + 1;
    }
    
    if (found == true)
        return ind;
    else
        return -1;
}
