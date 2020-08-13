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
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];

	unordered_set<int, custom_hash> s;
	for (int i = 0; i < 2 * n; i++) {
		if (!s.count(a[i])) {
			s.insert(a[i]);
			cout << a[i] << " ";
		}
	}
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