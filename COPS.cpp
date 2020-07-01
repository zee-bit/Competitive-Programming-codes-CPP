#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, m, x, y;
	cin>>t;
	while(t--) {
		cin>>m>>x>>y;
		vector<int> a(m), ans(101,1);
		for(int i=0; i<m; i++) 
			cin>>a[i];
		sort(a.begin(),a.end());
		int prod=x*y;
		for(int i=0; i<m; i++) {
			int j=prod>=a[i]?1:a[i]-prod;
			for(; (j<=prod+a[i] && j<=100); j++) 
				ans[j]=0;
		}
		int s=0;
		for(int i=1; i<=100; i++)
			s+=ans[i];
		cout<<s<<"\n";
	}
	return 0;
}