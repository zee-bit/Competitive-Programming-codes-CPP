#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
 
typedef long long ll;
const ll mod = 1ll<<32ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	ll q, a, b, s;
	cin>>q>>s>>a>>b;
	ll sum=0;
	bitset<mod/2ll+1ll> vis;
	for(ll i=1; i<=q; i++) {
		if(s&1) {
			if(!vis[s/2]) {
				vis[s/2]=true;
				sum+=s/2;
			}
		}
		else {
			if(vis[s/2]) {
				vis[s/2]=false;
				sum-=s/2;
			}
		}
		s=(a*s+b)%mod;
	}
	cout<<sum<<"\n";
	return 0;
}