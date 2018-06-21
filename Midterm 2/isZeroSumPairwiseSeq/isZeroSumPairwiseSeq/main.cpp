//
//  main.cpp
//  isZeroSumPairwiseSeq
//
//  Created by NomNomNam on 6/7/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//
//  3, -7, 0, 6, -6, 0, 7, -3 is a zero sum pairwise seq

#include <iostream>
using namespace std;

bool isZeroSumPairwiseSeq(int seq[], int seqSize);

int main() {
    int seqSize = 8;
    int seq[8] = {3, -7, 0, 6, -6, 0, 7, -3};
    
    bool isZeroSum = isZeroSumPairwiseSeq(seq, seqSize);
    
    for (int i = 0; i < seqSize; i++) {
        cout<<seq[i]<<" ";
    }
    
    if (isZeroSum == true) {
        cout<<"is a zero sum pairwise sequence.\n";
    } else
        cout<<"is not a zero sum pairwise sequence.\n";
    
    return 0;
}

bool isZeroSumPairwiseSeq(int seq[], int seqSize) {
    int i, zeroSum = 0;
    
    if (seqSize == 0) {
        return true;
    } else {
        isZeroSumPairwiseSeq(seq, seqSize - 1);
        for (i = 0; i < (seqSize / 2); i++) {
            zeroSum = seq[i] + seq[seqSize - i];
            if (zeroSum != 0)
                return false;
        }
        return true;
    }
}
