#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	if (2 * n <= s) {
		cout << "YES\n";
		for (int i = 1; i < n; i++)
			cout << 2 << " ";
		cout << s - (2 * (n - 1)) << "\n";
		cout << "1\n";
	}
	else
		cout << "NO\n";
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