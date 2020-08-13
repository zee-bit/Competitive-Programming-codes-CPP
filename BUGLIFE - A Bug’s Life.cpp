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

// 0 -> female, 1 -> male
bool vis[2001], sex[2001];
vector<int> a[2001];

bool dfs(int v, bool s) {
	vis[v] = true;
	sex[v] = s;
	for (int child : a[v]) {
		if (!vis[child]) {
			if (dfs(child, !s) == false)
				return false;
		}
		else {
			if (sex[v] == sex[child])
				return false;
		}
	}
	return true;
}

void solve(int sc) {
	int n, e, u, v;
	cin >> n >> e;

	for (int i = 1; i <= n; i++) {
		a[i].clear();
		vis[i] = 0;
	}
	for (int i = 1; i <= e; i++) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (dfs(i, 0) == false) {
				flag = false;
				break;
			}
		}
	}
	if (!flag) {
		cout << "Scenario #" << sc << ":\n";
		cout << "Suspicious bugs found!\n";
	}
	else {
		cout << "Scenario #" << sc << ":\n";
		cout << "No suspicious bugs found!\n";
	}
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
	for (int i = 1; i <= t; i++)
		solve(i);
	return 0;
}