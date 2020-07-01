#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, num2 = 0, num3 = 0;
	cin >> n;
	while (n % 2 == 0) {
		n /= 2;
		num2++;
	}
	while (n % 3 == 0) {
		n /= 3;
		num3++;
	}
	if (n == 1) {
		if (num2 <= num3)
			cout << (num3 - num2) + num3 << "\n";
		else
			cout << "-1\n";
	}
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