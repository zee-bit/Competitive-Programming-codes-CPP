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
#define maxN 10005

vector<int> ar[maxN], ord, sol(maxN);
bool vis[maxN];
int killed, injured, mx;

int dfs(int node) {
	int tot = 0;
	vis[node] = true;
	mx = max(mx, sol[node]);
	for (int child : ar[node]) {
		if (!vis[child])
			tot += dfs(child);
	}
	tot += sol[node];
	return tot;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	rep(i, 1, n + 1) {
		cin >> sol[i];
	}
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	rep(i, 1, n + 1) {
		if (!vis[i]) {
			int total = dfs(i);
			cout << total << " " << mx << "\n";
			ord.pb(mx);
			killed += sol[mx];
			injured += total - sol[mx];
			mx = 0;
		}
	}
	// sort(all(ord));
	// cout << killed << " " << injured << "\n";
	// for (int i : ord)
	// 	cout << i << " ";
	// cout << "\n";
	return 0;
}