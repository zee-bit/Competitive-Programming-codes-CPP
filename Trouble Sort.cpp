#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	bool isZero = false, isOne = false;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i] == 0 ? isZero = true : isOne = true;
	}

	if (isOne && isZero)
		cout << "Yes\n";
	else {
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
	}
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