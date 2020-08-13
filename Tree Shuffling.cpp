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

vector<int> a(maxN), b(maxN), c(maxN), ar[maxN];
bool vis[maxN];
int cost;

void dfs(int node) {
	vis[node] = true;
	for (int child : ar[node]) {
		if (!vis[child]) {
			a[child] = min(a[child], a[node]);
			dfs(child);
		}
	}
	if (b[node] != c[node])
		cost += a[node];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u, v, b_z = 0, b_o = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (b[i] != c[i]) {
			if (b[i] == 0)
				b_z++;
			else
				b_o++;
		}
	}

	if (b_z != b_o) {
		cout << "-1";
		return 0;
	}

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}

	dfs(1);
	cout << cost;
	return 0;
}