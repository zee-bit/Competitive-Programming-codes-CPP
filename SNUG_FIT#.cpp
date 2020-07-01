#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, n, s=0;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> a(n), b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i=0;i<n;i++) {
			s+=min(a[i],b[i]);
		}
		cout<<s<<"\n";
		s=0;
	}
	return 0;
}