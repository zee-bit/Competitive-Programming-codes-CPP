#include <bits/stdc++.h>
using namespace std;

int calcRem(int n, int k) {
	// int retVal = 1;
	// //if (k == 1) n--;
	// if (n / k == 0)
	// 	return 1;
	// else if (n / k < 0)
	// 	return 0;
	// return n / k;
	if (n <= 0)
		return 0;
	return 1 + calcRem(n - k - 1, k);
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0, firstOne = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') {
			firstOne = i;
			break;
		}
	if (firstOne == -1) {
		cout << calcRem(n, k) << "\n";
		return;
	}
	// if (firstOne - k > 0)
	ans = calcRem(firstOne - k, k);
	for (int i = firstOne + 1; i < n; i++) {
		if (s[i] == '1') {
			int diff = i - firstOne - (2 * k) - 1;
			//if (diff > 0) {
			ans += calcRem(diff, k);
			//}
			firstOne = i;
		}
	}
	ans += calcRem(n - firstOne - k - 1, k);
	cout << ans << "\n";
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