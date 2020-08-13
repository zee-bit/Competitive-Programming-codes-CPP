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

vector<int> ar[maxN];
bool vis[maxN], cats[maxN];
int m, ans;

void dfs(int node, int c) {
	vis[node] = true;
	if (cats[node])
		c++;
	else
		c = 0;
	if (c > m)
		return;
	for (int child : ar[node]) {
		if (!vis[child]) {
			dfs(child, c);
		}
	}
	if (node != 1 && ar[node].size() == 1)
		ans++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u, v;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> cats[i];

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << "\n";
	return 0;
}