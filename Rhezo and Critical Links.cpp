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

vector<int> ar[maxN], inTime(maxN), low(maxN), cc(maxN), numCC(maxN), sz(maxN);
int timer, ans, p, cnt, c;
bool vis[maxN];

void ddffss(int node) {
	cc[node] = c;
	numCC[c]++;
	vis[node] = true;
	for (int child : ar[node]) {
		if (!vis[child]) {
			ddffss(child);
		}
	}
}

void dfs(int node, int par = -1) {
	vis[node] = true;
	sz[node] = 1;
	low[node] = inTime[node] = timer++;
	for (int child : ar[node]) {
		if (child == par)
			continue;
		if (vis[child]) {
			low[node] = min(low[node], inTime[child]);
		}
		else {
			dfs(child, node);
			sz[node] += sz[child];
			if (low[child] > inTime[node]) {
				if (abs(sz[child] - (numCC[cc[node]] - sz[child])) < p)
					ans++;
			}
			low[node] = min(low[node], low[child]);
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
	int n, m;
	cin >> n >> m >> p;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	rep(i, 1, n + 1) {
		if (!vis[i]) {
			ddffss(i);
			c++;
		}
	}
	rep(i, 0, n + 1) {
		vis[i] = false;
	}
	rep(i, 1, n + 1) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	cout << ans << "\n";
	return 0;
}