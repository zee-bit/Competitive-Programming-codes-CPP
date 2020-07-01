#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int cP = n / k;
	float rem = m - cP;
	if (rem <= 0)
		cout << m << "\n";
	else {
		int maxToOthers = ceil(rem / float(k - 1));
		if (maxToOthers == cP)
			cout << "0\n";
		else
			cout << cP - maxToOthers << "\n";
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