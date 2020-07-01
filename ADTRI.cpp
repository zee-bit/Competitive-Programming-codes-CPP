#include <bits/stdc++.h>
using namespace std;
typedef long ll;

const ll N=5000002;

bool isPrime[N], isHyp[N];
vector<ll> prime;

void ansfunc() {
	for(ll i=0;i<N;i++) {
		isHyp[i]=false;
		isPrime[i]=true;
	}
	//Sieve of Eratosthenes
	isPrime[0] = isPrime[1] =false;
	for(ll i=2; i<N; i++) {
		if(isPrime[i])
			for(ll j=i*2;j<N;j+=i)
				isPrime[j]=false;
	}
	for(ll i=2;i<N;i++) {
		if(isPrime[i] == true && i%4==1) 
			prime.push_back(i);
	}
	for(ll i=0;i<prime.size();i++) {
		for(ll j=prime[i]; j<N; j+=prime[i])
			isHyp[j]=true;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ansfunc();
	ll t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		if(isHyp[n])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}