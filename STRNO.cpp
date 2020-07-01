#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll primeFactors(ll n) {
	ll ret_val=0;
	while(n%2==0) {
		ret_val++;
		n/=2;
	}
	for(ll i=3; i<=sqrt(n); i+=2) {
		while(n%i==0) {
			ret_val++;
			n/=i;
		}
	}
	if(n>2)
		ret_val++;
	return ret_val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, x, k;
	cin>>t;
	while(t--) {
		cin>>x>>k;
		if(k>x)
			cout<<"0\n";
		else {
			ll num=primeFactors(x);
			if(k>=1 && k<=num)
				cout<<"1\n";
			else
				cout<<"0\n";
		}
	}
	return 0;
}