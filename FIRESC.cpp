#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

vector<int> a[100001];
bool vis[100001];
int nv;

void dfs(int v) {
	vis[v] = true;
	nv++;
	for (int child : a[v]) {
		if (!vis[child])
			dfs(child);
	}
}

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	int cc = 0;
	ll p = 1;
	for (int i = 1; i <= n; i++) {
		a[i].clear();
		vis[i] = false;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cc++;
			nv = 0;
			dfs(i);
			p = (p * nv) % mod;
		}
	}
	cout << cc << " " << p << "\n";
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