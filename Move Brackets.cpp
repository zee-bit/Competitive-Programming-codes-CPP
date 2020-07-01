#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	int len = s.length();
	stack<char> st;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			st.push(s[i]);
		else if (st.empty() && s[i] == ')')
			ans++;
		else
			st.pop();
	}
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