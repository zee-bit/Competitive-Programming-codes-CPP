#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a >= c)
		cout << "-1 ";
	else
		cout << "1 ";
	if (c >= a * b)
		cout << "-1\n";
	else {
		cout << (c / a) + 1 << '\n';
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