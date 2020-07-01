#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n][m];
	unordered_set<int> r, c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				r.insert(i);
				c.insert(j);
			}
		}
	int turn = 0;
	//0 -> Ashish ; 1 -> Vivek
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && r.find(i) == r.end() && c.find(j) == c.end()) {
				r.insert(i);
				c.insert(j);
				turn++;
				turn %= 2;
			}
		}
	}
	turn == 0 ? cout << "Vivek\n" : cout << "Ashish\n";
}

int main() {
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