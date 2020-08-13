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
	vector<ll> a(n + 1), prefixSum(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		prefixSum[i] = prefixSum[i - 1] + a[i];

	int start = 0, end = 0;
	ll ans = 0;
	unordered_set<ll, custom_hash> s = {0};
	while (start < n) {
		while (end < n && !s.count(prefixSum[end + 1])) {
			++end;
			s.insert(prefixSum[end]);
		}
		ans += end - start;
		s.erase(prefixSum[start]);
		++start;
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
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}