#include <iostream>
using namespace std;

int factorial(int num);
int kCombinations(int n, int k);

int main() {
	int n, k, k_comb;

	cout<<"Please enter n and k (n>=k):"<<endl;
	cin>>n>>k;

	k_comb = kCombinations(n, k);

	cout<<n<<" choose "<<k<<" is ";
	cout<<k_comb<<endl;

	return 0;
}

int kCombinations(int n, int k) {
	int nFact, kFact, n_kFact;

	nFact = factorial(n);
	kFact = factorial(k);
	n_kFact = factorial(n-k);
	k_comb = nFact / (kFact * n_kFact);
}

int factorial(int num) {
	int factRes, i; 

	factRes = 1;

	for (i = 1; i <= num; i++)
		factRes *= i;

	return factRes;
}