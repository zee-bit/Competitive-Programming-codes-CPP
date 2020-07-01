#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++) 
			cin>>a[i];
		bool flag=true;
		for(int i=0; i<n; i++) {
			if(!flag)
				break;
			if(a[i]==1) {
				for(int j=i+1; j<i+6 && j<n; j++) {
					if(a[j]==1) {
						flag=false;
						break;
					}
				}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}