#include <iostream>
using namespace std;

double quad_cos(double x, int n);
double linear_cos(double x, int n);
double power(double base, int n);
double factorial(int n);

int main() {
    double quad_res, linear_res;
    
    cout.precision(30);
    for (int i = 1; i <= 10; i++) {
        quad_res = quad_cos(1, i);
        linear_res = linear_cos(1, i);
        cout<<quad_res<<" "<<linear_res<<endl;
    }
    return 0;
}

double quad_cos(double x, int n){
    double sum;
    double currTerm;
    int count, sign;
    
    sum = 0;
    for (count = 0, sign = 1; count <= (n-1); count++, sign *= -1) {
        currTerm = power(x, 2*count) / factorial(2*count);
        sum += sign*currTerm;
    }
    return sum;
}

// assume exp >= 0
double power(double base, int n){
    double res;
    int count;
    
    res = 1;
    for (count = 1; count <= n; count++) {
        res *= base;
    }
    return res;
}

// assume n >= 0
double factorial(int n){
    double res;
    int count;
    
    res = 1;
    for (count = 1; count <= n; count++) {
        res *= count;
    }
    return res;
}

double linear_cos(double x, int n){
    double sum;
    double currTerm, currPower, currFacorial;
    int count, sign;
    
    sum = 0;
    currPower = 1;
    currFacorial = 1;
    sign = 1;
    for (count = 0; count <= (n-1); count++) {
        currTerm = currPower / currFacorial;
        sum += sign*currTerm;
        
        currPower *= (x*x);
        currFacorial *= (2*count + 1) * (2*count + 2);
        sign *= -1;
    }
    return sum;
}