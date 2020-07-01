#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		vector<int> a(n);
		for(int i=0; i<n; ++i) 
			cin>>a[i];
		int i=1;
		while(i<n) {
			if(a[0]+a[i]<=m) {
				a[0]+=a[i];
				a[i]=0;
			}
			else {
				a[i]-=m-a[0];
				a[0]=m;
				break;
			}
			i++;
		}
		cout<<a[0]<<"\n";
	}
	return 0;
}