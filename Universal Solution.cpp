#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

void solve() {
	string s;
	cin >> s;
	string counter = "";
	int P = 0, R = 0, S = 0;
	for (char c : s) {
		if (c == 'R') R++;
		if (c == 'S') S++;
		if (c == 'P') P++;
	}
	char ans;
	int mx = max({R, S, P});
	if (mx == R) ans = 'P';
	if (mx == P) ans = 'S';
	if (mx == S) ans = 'R';
	for (int i = 0; i < int(s.size()); i++)
		cout << ans;
	cout << '\n';
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