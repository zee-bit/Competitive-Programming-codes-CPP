#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, x, y, tot = 0;
	cin >> n >> m >> x >> y;
	vector<vector<char> > a(n, vector<char> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			tot += a[i][j] == '.';
		}
	if (2 * x <= y)
		cout << tot * x << "\n";
	else {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cont_white = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') {
					ans += ((cont_white / 2) * y + (cont_white % 2) * x);
					cont_white = 0;
				}
				else
					cont_white++;
			}
			ans += ((cont_white / 2) * y + (cont_white % 2) * x);
		}
		cout << ans << "\n";
	}
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