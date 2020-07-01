#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> r(n);
	vector<int> b(n);
	int one=0;
	for(int i=0; i<n; i++) {
		cin>>r[i]; 
		if(r[i]==1)
			one++;
	}
	for(int i=0; i<n; i++) 
		cin>>b[i];
	if(one==0) {
		cout<<"-1\n";
		return 0;
	} 
	bool flag=true;
	for(int i=0; i<n ; i++) {
		if(r[i]!=b[i]) {
			flag=false;
			break;
		}
	}
	if(flag) {
		cout<<"-1\n";
		return 0;
	}
	else {
		int r_sum=0, b_sum=0;
		vector<int> s(n,-1);
		for(int i=0; i<n; ++i) {
			if(r[i]==0) {
				s[i]=1;
				r_sum+=r[i]*1;
				b_sum+=b[i]*1;
			}
		}
	}
}