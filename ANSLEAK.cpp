#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, k, x;
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		vector<vector<int> > c(n);
		for(int i=0; i<n; i++) {
			for(int j=0; j<k; j++) { 
				cin>>x;
				c[i].push_back(x);
			}
		}
		for(int i=0; i<n; i++) {
			int ma,ctr=0,max_ctr=0;
			for(int j=1; j<=m; j++) {
				ctr=0;
				for(int l=0; l<k; l++) {
					if(c[i][l]==j)
						ctr++;
				}
				if(ctr>=max_ctr) {
					max_ctr=ctr;
					ma=j;
				}
			}
			cout<<ma<<" ";
		}
		cout<<"\n";
	}
	return 0;
}