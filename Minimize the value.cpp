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
#define maxN 100002

vector<ll> ar[maxN], val(maxN);
bool vis[maxN];
ll ans, n, x;

ll dfs(int node) {
	vis[node] = true;
	ll s = val[node];
	for (int child : ar[node]) {
		if (!vis[child]) {
			s += dfs(child);
		}
	}
	ans += s;
	return s;
}

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = true;
	if (ar[src].size() <= 1) {
		ar[n + 1].pb(src);
		ar[src].pb(n + 1);
		return;
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : ar[curr]) {
			if (vis[child])
				continue;
			if (ar[child].size() <= 2) {
				ar[n + 1].pb(child);
				ar[child].pb(n + 1);
				return;
			}
			q.push(child);
			vis[child] = true;
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
	cin >> n >> x;
	rep(i, 1, n + 1) {
		cin >> val[i];
	}
	val[n + 1] = x;
	rep(i, 1, n) {
		ll u , v;
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	bfs(1);
	memset(vis, false, sizeof(vis));
	dfs(1);
	cout << ans << "\n";
	return 0;
}