#include <iostream>
using namespace std;

int main() {
    int currElem;
    int sum, count, evensCount;
    bool seenEndOfSeq;
    
    cout<<"Please enter a sequence of positive integers."<<endl;
    cout<<"End by typing -1:"<<endl;
    
    sum = 0;
    count = 0;
    evensCount = 0;
    seenEndOfSeq = false;
    while (seenEndOfSeq == false) {
        cin>>currElem;
        if(currElem == -1)
            seenEndOfSeq = true;
        else{
            sum += currElem;
            count++;
            if((currElem % 2) == 0)
                evensCount++;
        }
    }
    cout<<"Sum is "<<sum<<endl;
    cout<<"Average is: "<<(double)sum/(double)count<<endl;
    cout<<"Number of evens: "<<evensCount<<endl;
    return 0;
}