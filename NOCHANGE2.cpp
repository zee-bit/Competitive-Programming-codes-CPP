#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, n, p;
	cin>>t;
	while(t--) {
		bool flag=false;
		cin>>n>>p;
		vector<ll> d(n);
		vector<ll> ans(n, 0);
		for(ll i=0; i<n; i++) 
			cin>>d[i];
		for(ll i=0; i<n; i++) {
			if(p%d[i]!=0) {
				ans[i]=p/d[i]+1;
				flag=true;
				break;
			}
		}
		if(!flag) {
			for(ll i=0; i<n-1; i++) {
				if(d[i+1]%d[i]!=0) {
					ans[i+1]=1;
					ans[i]=((p-d[i+1])/d[i])+1;
					flag=true;
					break;
				}
			}
		}
		if(!flag) 
			cout<<"NO\n";
		else {
			cout<<"YES ";
			for(ll i=0; i<n; i++) {
				cout<<ans[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}