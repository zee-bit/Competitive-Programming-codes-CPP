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
		vector<int> p(n), f(n);
		for(int i=0; i<n; i++) 
			cin>>f[i];
		for(int i=0; i<n; i++) 
			cin>>p[i];
		int min=0, cost;
		for(int i=1; i<=m; i++) {
			cost=0;
			bool pres=false;
			for(int j=0; j<n; j++) {
				if(f[j]==i) {
					cost=cost+p[j];
					pres=true;
				}
			}
			if(pres) {
				if(cost==0) {
					min=cost;
					break;
				}
				if(min==0)
					min=cost;
				if(cost<min)
					min=cost;
			}
		}
		cout<<min<<"\n";
	}
	return 0;
}