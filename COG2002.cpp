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
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n + 2);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = a[0];
	a[n + 1] = a[1];
	ans = a[0] + a[1] + a[2];
	for (int i = 2; i < n + 1; i++) {
		ans = max(ans, a[i] + a[i - 1] + a[i - 2]);
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