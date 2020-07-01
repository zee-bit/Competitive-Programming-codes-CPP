#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, s, n;
	cin>>t>>s;
	while(t--) {
		cin>>n;
		vector<int> a(n), b(n);
		for(int i=0; i<n; i++) 
			cin>>a[i];
		for(int i=0; i<n; i++) 
			cin>>b[i];
		sort(a.begin(),a.end());
		sort(b.begin(), b.end());
		bool ans=true;
		vector<int> present;
		for(int i=0; i<n; i++) {
			if(present.empty()) 
				present.push_back(a[i]);
			else if(find(present.begin(), present.end(), a[i]) != present.end()) 
				present.push_back(a[i]);
			else {
				ans=false;
				break;
			}
			if(b[i]>a[i]) {
				present.push_back(b[i]);
			}
			else {
				ans=false;
				break;
			}
		}
		if(ans) 
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}