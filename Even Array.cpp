#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (a[i] % 2)
				even++;
		}
		else {
			if (a[i] % 2 == 0)
				odd++;
		}
	}
	if (even == odd)
		cout << even << "\n";
	else
		cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}