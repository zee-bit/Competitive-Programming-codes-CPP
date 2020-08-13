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

vector<int> ar[100001];
bool vis[100001], col[100001];

void dfs(int node, int c) {
	vis[node] = true;
	col[node] = c;
	for (int child : ar[node]) {
		if (!vis[child]) {
			dfs(child, !c);
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
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	dfs(1, 0);
	ll black = 0, white = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0)
			black++;
		else
			white++;
	}
	ans = (black * white) - (n - 1);
	cout << ans << "\n";
	return 0;
}