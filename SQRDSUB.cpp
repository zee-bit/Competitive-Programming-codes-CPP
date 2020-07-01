// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// typedef long long ll;

// bool isPerfectSquare(ll x) {
// 	float sr=sqrt(x);
// 	return ((sr-floor(sr))==0);
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	int t, n;
// 	cin>>t;
// 	while(t--) {
// 		cin>>n;
// 		vector<ll> a(n);
// 		for(int i=0; i<n; i++) {
// 			cin>>a[i];
// 			a[i]=abs(a[i]);
// 		}
// 		ll ans=0;
// 		for(int i=0; i<n ;i++) {
// 			ll p=a[i];
// 			if(isPerfectSquare(p))
// 				ans++;
// 			else {
// 				ll ch=sqrt(p)+1;
// 				ch=ch*ch-p;
// 				if(isPerfectSquare(ch))
// 					ans++;
// 			}
// 			for(int j=i+1; j<n; j++) {
// 				p*=a[j];
// 				if(isPerfectSquare(p))
// 					ans++;
// 				else {
// 					ll che=sqrt(p)+1;
// 					che=che*che-p;
// 					if(isPerfectSquare(che))
// 						ans++;
// 				}
// 			}
// 		}
// 		cout<<ans<<"\n";
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
// int powerOfTwo(int n) {
// 	if((n==0) || (ceil(log2(n))!=floor(log2(n))))
// 		return 0;
// 	return log2(n);
// }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<ll> a(n);
		vector<ll> ch(n);
		for(ll i=0; i<n; i++) {
			cin>>a[i];
			if(a[i]%2!=0) 
				ch[i]=0;
			else if(a[i]%4==0)
				ch[i]=2;
			else if((a[i]/2)%2!=0)
				ch[i]=1;
		}
		if(n==1) {
			if(ch[0]==1)
				cout<<"0\n";
			else
				cout<<"1\n";
			continue;
		}
		ll ans=n*(n+1)/2, z=0;
		for(ll i=0; i<n; i++) {
			if(ch[i]==0) 
				z++;
			else if(ch[i]==1) {
				for(ll j=i+1; j<n; j++) {
					if(ch[j]==2 || ch[j]==1 || j==n-1) {
						ll r=(j==n-1 && ch[j]==0)?j-i:j-i-1, sub=0;
						if(r==0 && z==0) 
							sub=1;
						else if(z==0 || r==0)
							sub=z+r+1;
						else 
							sub=z+r+2;
						if(r!=0 && z!=0)
							sub+=r*z-1;
						ans-=sub;
						z=0;
						break;
					}
				}
				if(z==0 && i==n-1)
					ans--;
				if(z!=0) {
					ans-=(z+1);
					z=0;
				}
			}
			else 
				z=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}