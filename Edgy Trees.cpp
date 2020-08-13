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

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 200001
#define MOD 1000000007

vector<ll> ar[maxN];
bool vis[maxN];
ll cnt;

ll modExp(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp % 2) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

void dfs(ll node) {
	vis[node] = true;
	cnt++;
	for (ll child : ar[node]) {
		if (!vis[child])
			dfs(child);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, k, u, v, c;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> c;
		if (!c) {
			ar[u].pb(v);
			ar[v].pb(u);
		}
	}
	ll ans;
	ans = modExp(n, k);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs(i);
			// Here MOD is added because if ans is negative
			// then ans % MOD will be negative, hence doing
			// like this will prevent ans from beign negative.
			ans = (ans - modExp(cnt, k) + MOD) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}