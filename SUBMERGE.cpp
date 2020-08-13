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
#define maxN 10001

vector<int> ar[maxN], inTime(maxN), low(maxN);
bool vis[maxN];
set<int> ans;
int timer;

void dfs(int node, int par = -1) {
	vis[node] = true;
	inTime[node] = low[node] = ++timer;
	int ch = 0;
	for (int child : ar[node]) {
		if (child == par)
			continue;
		if (vis[child]) {
			low[node] = min(low[node], inTime[child]);
		}
		else {
			dfs(child, node);
			low[node] = min(low[node], low[child]);
			if (low[child] >= inTime[node] && par != -1)
				ans.insert(node);
			++ch;
		}
	}
	if (par == -1 && ch > 1)
		ans.insert(node);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, u, v;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++) {
			ar[i].clear();
			vis[i] = false;
			ans.clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			ar[u].pb(v);
			ar[v].pb(u);
		}

		int cnt = 0;
		rep(i, 1, n + 1) {
			if (!vis[i])
				dfs(i);
		}
		cout << ans.size() << "\n";
	}
	return 0;
}