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
#define maxN 100001

vector<int> ar[maxN], p(maxN), h(maxN), tot(maxN), g(maxN);
bool vis[maxN], isPoss = true;

void dfs(int node) {
	vis[node] = true;
	tot[node] = p[node];
	int good = 0;
	for (int child : ar[node]) {
		if (!vis[child]) {
			dfs(child);
			tot[node] += tot[child];
			good += g[child];
		}
	}
	g[node] = (tot[node] + h[node]) / 2;
	if ((tot[node] + h[node]) & 1) isPoss = false;
	if (g[node] > tot[node]) isPoss = false;
	if (good > g[node]) isPoss = false;
}

void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) {
		vis[i] = false;
		ar[i].clear();
	}
	rep(i, 1, n + 1)
	cin >> p[i];
	rep(i, 1, n + 1)
	cin >> h[i];

	int u, v;
	rep(i, 1, n) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	isPoss = true;
	dfs(1);
	if (isPoss)
		cout << "YES\n";
	else
		cout << "NO\n";
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
	while (t--) {
		solve();
	}
	return 0;
}