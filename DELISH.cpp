#include <bits/stdc++.h>
using namespace std;
typedef long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		vector<ll> sum(n), d(n);
		for(ll i=0; i<n; i++) 
			cin>>d[i];
		//sort(d.begin(),d.end());
		sum[0]=d[0];
		for(ll i=1; i<n; i++)
			sum[i]=sum[i-1]+d[i];
		ll max_del=0;
		for(ll i=0; i<n; i++) {
			ll x=min(d[i],sum[i]);
			ll y=sum[n-1]-x;
			max_del=max(abs(x-y),max_del);
		}
		cout<<max_del<<"\n";
	}
	return 0;
}