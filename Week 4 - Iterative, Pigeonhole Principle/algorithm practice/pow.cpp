#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    int count, currPower;
    
    cout<<"Please enter a positive integer"<<endl;
    cin>>n;
    
    cout<<"Using a while loop"<<endl;
    count = 1;
    while(count <= n){
        currPower = pow(2, count-1);
        cout<<count<<". "<<currPower<<endl;
        count++;
    }
    
    cout<<endl<<"Using a for loop"<<endl;
    for (count = 1; count <= n; count++) {
        currPower = pow(2, count-1);
        cout<<count<<". "<<currPower<<endl;
    }
    return 0;
}