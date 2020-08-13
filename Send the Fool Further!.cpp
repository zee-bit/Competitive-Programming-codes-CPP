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

vector<pair<int, int> > ar[101];
bool vis[101];
int cost[101], mx;

void dfs(int node) {
	vis[node] = true;
	for (auto child : ar[node]) {
		if (!vis[child.first]) {
			cost[child.first] = cost[node] + child.second;
			mx = max(mx, cost[child.first]);
			dfs(child.first);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u, v, c;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> c;
		ar[u].pb({v, c});
		ar[v].pb({u, c});
	}
	dfs(0);
	cout << mx << "\n";
	return 0;
}