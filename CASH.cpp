#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, n, k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<ll> a(n);
		for(int i=0; i<n; i++) 
			cin>>a[i];
		ll distro=0;
		for(int i=0; i<n; i++) {
			distro+=a[i]%k;
		}
		ll ans=distro%k;
		cout<<ans<<"\n";
	}
	return 0;
}