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

// There are various ways to solve this.
// Here, it is solved using DFS counting the number of
// connected components.
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> ar[10001];
bool vis[10001], storeUniques[10001];

void dfs(int node) {
	vis[node] = true;
	for (int child : ar[node]) {
		if (!vis[child])
			dfs(child);
	}
}

void calConnComp(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << "\n";
}

// This can also be solved by just counting
// unique value from p[i].

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u, ans = 0, ct = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> u;
		// if (u != i && (find(all(ar[i]), u) == ar[i].end())) {
		// 	ar[u].pb(i);
		// 	ar[i].pb(u);
		// }
		if (u != i)
			storeUniques[u] = true;
		else
			ct++;
	}
	for (int i = 1; i <= n; i++)
		ans += storeUniques[i];
	cout << ans / 2 + ct << "\n";
	//calConnComp(n);
	return 0;
}