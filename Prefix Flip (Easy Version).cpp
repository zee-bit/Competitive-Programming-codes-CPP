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
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

void solve() {
	string a, b;
	int n;
	cin >> n >> a >> b;
	vector<int> flips;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			flips.pb(i);
			flips.pb(0);
			flips.pb(i);
			a[i] = b[i];
		}
	}
	cout << flips.size() << " ";
	for (int i = 0; i < int(flips.size()); i++)
		cout << flips[i] + 1 << " ";
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