#include <iostream>
using namespace std;

int main() {
    int n;
    int line, count;
    
    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;
    
    cout<<"Printing a square:"<<endl;
    for (line = 1; line <= n; line++) {
        //1. print n stars
        for (count = 1; count <= n; count++) {
            cout<<"*";
        }
        //2. break the line
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"Printing a right triangle aligned to the left"<<endl;
    for (line = 1; line <= n; line++) {
        //1. print line stars
        for (count = 1; count <= line; count++) {
            cout<<"*";
        }
        //2. break the line
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"Printing a right triangle aligned to the right"<<endl;
    for (line = 1; line <= n; line++) {
        //1. print n-line spaces
        for (count = 1; count <= (n-line); count++) {
            cout<<" ";
        }
        //2. print line stars
        for (count = 1; count <= line; count++) {
            cout<<"*";
        }
        //3. break the line
        cout<<endl;
    }
    return 0;
}