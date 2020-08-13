#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//=======================================XXXXXXXXXXXXXXXX==========================================
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define N 1000001

vector<int> a[N], cc(N);
bool vis[N];

void dfs(int node, int c) {
	vis[node] = true;
	cc[node] = c;

	for (int child : a[node]) {
		if (!vis[child]) {
			dfs(child, c);
		}
	}
}

void solve() {
	int n, k, u, v;
	cin >> n >> k;
	for (int i = 1; i < N; i++) {
		a[i].clear();
		vis[i] = false;
	}
	vector<pair<int, int> > store;
	string c;
	for (int i = 0; i < k; i++) {
		cin >> u >> c >> v;
		if (c == "=") {
			a[u].pb(v);
			a[v].pb(u);
		}
		else
			store.pb({u, v});
	}
	int con = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, con);
			con++;
		}
	}
	for (int i = 0; i < int(store.size()); i++) {
		u = store[i].first;
		v = store[i].second;
		if (cc[u] == cc[v]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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