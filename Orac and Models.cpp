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
	int n;
	cin >> n;
	vector<int> a(n + 1), dp(n + 1);
	for (int i = 1 ; i <= n; i++)
		cin >> a[i];
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				int f = j, s = i / j;
				if (a[i] > a[f])
					mx = max(mx, dp[f]);
				if (a[i] > a[s])
					mx = max(mx, dp[s]);
			}
		}
		dp[i] = mx + 1;
	}
	int ans = -1;
	rep(i, 1, n + 1) {
		ans = max(ans, dp[i]);
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