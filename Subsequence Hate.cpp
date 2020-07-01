#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int len = s.length();
	int ans = 0, total_0 = 0, total_1 = 0;
	for (int i = 0; i < len; i++) {
		total_1 += s[i] == '1';
		total_0 += s[i] == '0';
	}
	int left_0 = 0, left_1 = 0;
	ans = min(total_0, total_1);

	for (int i = 0; i < len; i++) {
		left_1 += s[i] == '1';
		left_0 += s[i] == '0';

		// For the sequence 111...000...
		ans = min(ans, left_0 + total_1 - left_1);

		//For the sequence 000...111...
		ans = min(ans, left_1 + total_0 - left_0);
	}
	cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}