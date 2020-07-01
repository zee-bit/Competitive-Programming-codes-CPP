#include <iostream>
#include <vector>
#include <algorithm>
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
		sort(a.begin(), a.end());
		if(n%2)
			cout<<a[n/2]<<" ";
		for(int i=n/2-1; i>=0; i--) 
			cout<<a[n-i-1]<<" "<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}