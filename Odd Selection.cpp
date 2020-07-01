#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2)
			odd++;
		else even++;
	}
	if (odd == 0) {
		cout << "No\n";
		return ;
	}

	if (odd % 2 == 0)
		odd--;

	if (x % 2 == 0) {
		if (odd > x) {
			if (even >= 1)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else {
			if (even >= x - odd)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	else {
		if (odd >= x)
			cout << "Yes\n";
		else {
			if (x - odd <= even)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}