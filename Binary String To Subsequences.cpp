#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//==========================XXXXXXXXXXXXXXXX=============================

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {
	int n, k = 0;
	cin >> n;
	string s;
	cin >> s;
	vector<int> ans, p[2];
	for (int i = 0; i < n; i++) {
		int x = s[i] - '0';
		if (p[!x].empty()) {
			p[x].pb(++k);
			ans.pb(p[x].back());
		}
		else {
			p[x].pb(p[!x].back());
			p[!x].pop_back();
			ans.pb(p[x].back());
		}
	}
	cout << k << "\n";
	rep(i, 0, n)
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