#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	vector<int> ans;
	ans.pb(p[0]);
	for (int i = 1; i < n - 1; i++) {
		if ((p[i] > p[i - 1] && p[i] > p[i + 1]) || (p[i] < p[i - 1] && p[i] < p[i + 1]))
			ans.pb(p[i]);
	}
	ans.pb(p[n - 1]);
	int ans_size = ans.size();
	cout << ans_size << "\n";
	for (int i = 0; i < ans_size; i++)
		cout << ans[i] << " ";
	cout << "\n";
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