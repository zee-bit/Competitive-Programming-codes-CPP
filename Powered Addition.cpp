#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		int m=0, ans=0;
		for(int i=1; i<n; i++) {
			if(a[i]<a[i-1]) {
				m=max(m,abs(a[i-1]-a[i]));
				a[i]=a[i-1];
			}
		}
		if(m)
			ans=(int)log2(m)+1;
		cout<<ans<<"\n";
	}
	return 0;
}