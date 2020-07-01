#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, c, best, worst;
	cin >> n;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	
	vector<int> diff(n - 1);
	for(int i = 1; i < n; i++) 
		diff[i - 1] = a[i] - a[i - 1];
		
	best = 10;
	worst = 0;
	c = 1;
	for(int i = 0; i < n - 1; i++) {
		if(diff[i] <= 2) 
			c++;
		else {
			best = min(c, best);
			worst = max(c, worst);
			c = 1;
		}
	}
	best = min(c, best);
	worst = max(c, worst);
	cout << best << " " << worst << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) 
		solve();
	return 0;
}
