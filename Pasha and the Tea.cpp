#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, w;
	cin >> n >> w;
	vector<int> a(2 * n);
	for (int i = 0; i < (2 * n); i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	double max_X = w / (3.0 * n);
	max_X = min(max_X, double(a[0]));
	max_X = min(max_X, a[n] / 2.0);
	cout << fixed << (max_X * n) + (2.0 * max_X * n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}