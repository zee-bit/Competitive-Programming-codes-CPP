#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 998244353

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, l, r, n, q;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> a(n);
		for(int i=0; i<n; i++) 
			cin>>a[i];
		cin>>q;
		while(q--) {
			cin>>l>>r;
			int size=r-l+1;
			if(size==1) {
				cout<<1<<"\n";
			}
			else if(size==2) {
				if(a[l-1]==a[r-1])
					cout<<1<<"\n";
				else
					cout<<0<<"\n";
			}
			else {
				vector<int> vis(n);
				int count=0, m=0, c=0;
				for(int i=l-1; i<r; i++) {
					if(find(vis.begin(), vis.end(),a[i]) == vis.end()) {
						vis.push_back(a[i]);
						for(int j=i+1; j<r; j++) {
							if(a[i]==a[j]) {
								count++;
								break;
							}
						}
					}
				}
				if(count==0) {
					if(size%2==0) 
						cout<<0<<"\n";
					else 
						cout<<size<<"\n";
				}
				else if(count==1) {

					for(int i=l-1; i<r; i++) {
						c=0;
						for(int j=i+1; j<r; j++) {
							if(a[i]==a[j]) 
								c++;
						}
						m=max(c,m);
					}

					if((size-m)%2==0)
						cout<<m+1<<"\n";
					else 
						cout<<1<<"\n";
				}
				else {
					vector<int> freq(n,1);
					int k=0;
					for(int i=l-1; i<r; i++) {
						for(int j=i+1; j<r; j++) {
							if(a[i]==a[j]) {
								freq[k]++;
							}
						}
						k++;
					}
					sort(freq.begin(), freq.end(), greater<int>());
					int ans=0, c=0;
					for(int i=0; freq[i+1]!=1; i++) {
						if(freq[i]==freq[i+1])
							c++;
					}
				}
			}
		}
	}
	return 0;
}