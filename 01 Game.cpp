#include <bits/stdc++.h>
using namespace std;

// Easy Solution (Inspired by tmwilliamlin)
void solve() {
	string s;
	cin >> s;
	int c[] = {0, 0};
	for (char d : s)
		c[d - '0']++;
	cout << ((min(c[0], c[1]) & 1) ? "DA\n" : "NET\n");
}

// Complex Solution
void solve2() {
	string s;
	cin >> s;
	char f = s[0];
	int ctr = 0;
	stack<char> st;
	st.push(s[0]);
	for (int i = 1; i < int(s.length()); i++) {
		if (s[i] == f)
			st.push(s[i]);
		else {
			if (!st.empty()) {
				st.pop();
				ctr++;
			}
			else {
				f = s[i];
				st.push(s[i]);
			}
		}
	}
	if (ctr % 2 == 0)
		cout << "NET\n";
	else
		cout << "DA\n";
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