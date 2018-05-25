#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ACTUAL_PIN_NUM[5] = {1, 2, 3, 4, 5};

int main() {
    srand(time(0));
    int randNum;
    int numArrSize = 10;
    int numArr[10];
    int pinArrSize = 10;
    int pinArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int enteredNum;
    int enteredArrSize = 5;
    int enteredNumArr[5];
    
    //
    cout<<"PIN:\t";
    for (int i = 0; i < pinArrSize; i++) {
        cout<<pinArr[i]<<" ";
    }
    
    cout<<endl;
    
    cout<<"NUM:\t";
    for (int i = 0; i < numArrSize; i++) {
        randNum = ((rand() % 3) + 1);
        numArr[i] = randNum;
        cout<<numArr[i]<<" ";
    }
    
    cout<<"Enter the 5 digit NUM separated by a space corresponding to your PIN number: ";
    for (int i = 0; i < enteredArrSize; i++) {
        cin>>enteredNum;
        enteredNumArr[i] = enteredNum;
    }
    
    for (int i = 0; i < enteredArrSize; i++) {
        cout<<enteredNumArr[i];
    }
    
    cout<<endl;
}
