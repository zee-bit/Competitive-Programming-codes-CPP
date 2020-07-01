#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b, int c, int d) {
	return a>b?a>c?a>d?a:d:c>d?c:d:b>c?b>d?b:d:c>d?c:d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a, b, x, y;
	cin>>t;
	while(t--) {
		cin>>a>>b>>x>>y;
		int ans=max(x*b, (a-x-1)*b, y*a, (b-y-1)*a);
		cout<<ans<<"\n";
	}
	return 0;
}