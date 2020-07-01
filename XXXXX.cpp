#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	bool isPoss = false;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % x)
			isPoss = true;
	}
	if (!isPoss) {
		cout << "-1\n";
		return;
	}
	vector<int> prefixSum(n, 0);
	prefixSum[0] = a[0];
	for (int i = 1; i < n; i++)
		prefixSum[i] = a[i] + prefixSum[i - 1];
	int maxL = 1;
	for (int i = 0; i < n; i++) {
		if (prefixSum[i] % x)
			maxL = max(maxL, i + 1);
		if ((prefixSum[n - 1] - prefixSum[i]) % x)
			maxL = max(maxL, n - i - 1);
	}
	cout << maxL << "\n";
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