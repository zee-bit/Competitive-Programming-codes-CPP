#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, o = 0, e = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		o += (a[i] % 2 == 1);
		e += (a[i] % 2 == 0);
	}

	if (e % 2 == 0 && o % 2 == 0)
		cout << "YES\n";
	else {
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) {
				for (int j = 0; j < n; j++) {
					if (abs(a[i] - a[j]) == 1 && a[j] % 2 == 0) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
		cout << "NO\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}