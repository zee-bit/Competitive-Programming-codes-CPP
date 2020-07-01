#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, x, m, n;
	cin>>t;
	while(t--) {
		cin>>x>>n>>m;
		if(x<=10*m) {cout<<"YES\n"; continue;}
		while(x>20 && n!=0) {
			x=floor(x/2)+10;
			n--;
		}
		if(x>10*m)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}