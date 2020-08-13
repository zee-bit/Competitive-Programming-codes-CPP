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
	string t, s = "";
	cin >> t;
	int o = 0;
	for (int i = 0; i < int(t.length()); i++)
		if (t[i] == '1')
			o++;
	if (o == 0 || o == int(t.length())) {
		cout << t << "\n";
		return;
	}
	int l = 2 * t.length();
	for (int i = 0; i < l; i++) {
		if (i & 1)
			s += '1';
		else
			s += '0';
	}
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}