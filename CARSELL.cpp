#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		vector<ll> p(n);
		for(ll i=0; i<n; i++) 
			cin>>p[i];
		sort(p.begin(),p.end(),greater<ll>());
		ll ans=0;
		for(ll i=0; i<n; i++) {
			if(p[i]==0 || (p[i]-i)<=0)
				continue;
			else {
				ans+=(p[i]-i)%mod;
				ans%=mod;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}