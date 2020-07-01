#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t,n,m,i,j;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		long flag=0,top=0;
		long a[n];
		bool pres=false;
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		int len_b=(int)pow(2,n);
		long b[len_b];
		b[0]=0;
		for(i=0;i<n;i++) {
			for(j=0;j<=flag;j++) {
				top++;
				b[top]=a[i]+b[j];
			}
			flag=top;
		}
		for(i=1;i<len_b;i++) {
			if(b[i]==m) {
				pres=true;
			}
		}
		if(pres==true)
			cout<<"Yes";
		else
			cout<<"No";
	}
	return 0;
}	
			