#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int k, q;
	cin >> k >> q;
	vector<ll> a(k), b(k);
	
	for(int i = 0; i < k; i++)
		cin >> a[i];
	for(int i = 0; i < k; i++)
		cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<ll> ans;

	if(k >= 1000) {
		ll mx = a[999] + b[999];
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k, a[i] + b[j] <= mx; j++) 
				ans.push_back(a[i] + b[j]);
		}
	}
	else {
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) 
				ans.push_back(a[i] + b[j]);
		}
	}
	
	sort(ans.begin(), ans.end());
	while(q--) {
		int x;
		cin >> x;
		cout << ans[x - 1] << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
