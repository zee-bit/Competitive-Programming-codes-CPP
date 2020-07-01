#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, count=0;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1; i<n; i++) {
		if(a[i] != a[i-1])
			count++;
	}
	cout<<count<<"\n";
	return 0;
}