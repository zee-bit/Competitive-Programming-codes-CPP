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

ll maxSubarraySum(vector<int> &a) {
	if (a.size() == 0)
		return -1LL;
	ll currMax = a[0], globalMax = a[0], l = a.size();
	for (int i = 1; i < l; i++) {
		currMax = max(ll(a[i]), currMax + a[i]);
		globalMax = max(currMax, globalMax);
	}
	return globalMax;
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll ans = 0;
	for (int i = 0; i < n; i += 2)
		ans += a[i];

	vector<int> even, odd;
	for (int i = 0; i < n - 1; i += 2)
		even.pb(a[i + 1] - a[i]);
	for (int i = 1; i < n - 1; i += 2)
		odd.pb(a[i] - a[i + 1]);

	ll sEven = maxSubarraySum(even);
	ll sOdd = maxSubarraySum(odd);

	ll inc = max(sEven, sOdd);
	if (inc > 0)
		ans += inc;

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