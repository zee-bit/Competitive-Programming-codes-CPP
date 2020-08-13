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

int n;
bool vis[10001];
vector<int> a[10001];

void dfs(int v) {
	vis[v] = true;
	for (int child : a[v]) {
		if (!vis[child]) {
			dfs(child);
		}
	}
}

int countCC() {
	int c = 0;
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			c++;
			dfs(i);
		}
	}
	return c;
}

void solve() {
	int m, u, v, x = 1;
	cin >> n >> m;
	while (x <= m) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
		x++;
	}
	if (n == (m + 1)) {
		int cc = countCC();
		if (cc == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
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
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}