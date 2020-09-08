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
#define maxN 10005

vector<ll> ar[maxN], dp(maxN);
ll n, ans;

ll dfs(ll node) {
	for (ll child : ar[node]) {
		if (dp[child] > 0) {
			dp[node] += dp[child];
		}
		else
			dp[node] += dfs(child);
	}
	return dp[node];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	while (true) {
		ll u, v;
		cin >> u >> v;
		if (u == 0 && v == 0)
			break;
		ar[u].pb(v);
	}
	dp[n] = 1;
	dfs(1);
	cout << dp[1] << "\n";
	return 0;
}