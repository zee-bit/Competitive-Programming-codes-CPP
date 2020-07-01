#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, q;
	cin>>t;
	while(t--) {
		cin>>n>>q;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) 
			cin>>a[i];
		vector<vector <int> > qs(q, vector<int> (3));
		for(int i=0; i<q ;i++) 
			cin>>qs[i][0]>>qs[i][1]>>qs[i][2];
		for(int i=0; i<q; i++) {
			int ans=0;
			for(int j=qs[i][0]; j<qs[i][1]; j++) {
				if(a[j]<=qs[i][2] && a[j+1]>=qs[i][2])
					ans++;
				else if(a[j]>=qs[i][2] && a[j+1]<=qs[i][2])
					ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}