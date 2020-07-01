#include <bits/stdc++.h>
using namespace std;
//#define ios ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q, x;
	cin>>n>>m>>q;
	bitset<4001> ba[100002], bb[100002];
	for(int i=1; i<=n; i++) {
		cin>>x;
		ba[i]=ba[i-1];
		ba[i].flip(x);
	}
	for(int i=1; i<=m; i++) {
		cin>>x;
		bb[i]=bb[i-1];
		bb[i].flip(x);
	}
	int l1, l2, r1, r2;
	//bitset<4001> temp;
	while(q--) {
		cin>>l1>>r1>>l2>>r2;
		// temp=ba[r1];
		// temp^=ba[l1-1];
		// temp^=bb[r2];
		// temp^=bb[l2-1];
		cout<<(ba[l1-1]^ba[r1]^bb[l2-1]^bb[r2]).count()<<"\n";
	}
	return 0;
}