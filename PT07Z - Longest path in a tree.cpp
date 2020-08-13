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

vector<int> a[10001];
bool vis[10001];
int maxD, maxNode;

void dfs(int node, int d) {
	vis[node] = true;
	if (d > maxD) {
		maxD = d;
		maxNode = node;
	}
	for (int child : a[node]) {
		if (!vis[child]) {
			dfs(child, d + 1);
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
		a[u].pb(v);
		a[v].pb(u);
	}
	maxD = -1;
	dfs(1, 0);

	for (int i = 1; i <= n; i++)
		vis[i] = false;

	maxD = -1;
	dfs(maxNode, 0);
	cout << maxD << "\n";
	return 0;
}