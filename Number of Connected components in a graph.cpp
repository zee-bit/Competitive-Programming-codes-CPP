#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define maxN 1000001

vector<int> a[maxN];
bool vis[maxN];

void dfs(int v) {
	vis[v] = true;
	for (int i = 0; i < a[v].size(); i++) {
		if (!vis[a[v][i]])
			dfs(a[v][i]);
	}
}

int main() {
	int n, e, u, v;
	cin >> n >> e;
	while (e--) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}

	int cc_comp = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			cc_comp++;
		}
	}
	cout << cc_comp << "\n";
}