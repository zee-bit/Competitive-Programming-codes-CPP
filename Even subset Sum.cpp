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
		bool isDiv=false;
		int pos;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			if(a[i]%2==0 && !isDiv) {
				isDiv=true;
				pos=i+1;
			}
		}
		if(isDiv) 
			cout<<1<<"\n"<<pos<<"\n";
		else {
			int pos1=0, pos2=0, c=0;
			for (int i = 0; i < n; ++i) {
				if(c==2) break;
				if ( a[i] % 2 != 0 && c <= 2) {
					c++;
					if(!pos1)
						pos1=i+1;
					else 
						pos2=i+1;
				} 
			}
			if(c<2) {
				cout<<"-1\n";
				continue;
			}
			cout<<c<<"\n";
			cout<<pos1<<" "<<pos2<<"\n";
		}
	}
	return 0;
}