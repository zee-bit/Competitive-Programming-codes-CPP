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

//==========================XXXXXXXXXXXXXXXX==========================
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> a[1000001];
bool vis[1000001];
int dis[1000001];

void bfs(int src) {
	queue<int> q;
	vis[src] = true;
	dis[src] = 0;
	q.push(src);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : a[curr]) {
			if (!vis[child]) {
				q.push(child);
				dis[child] = dis[curr] + 1;
				vis[child] = true;
			}
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
	int n, e, u, v, m;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	cin >> m;
	while (m--) {
		cin >> u >> v;
		for (int i = 0; i < n; i++)
			vis[i] = false;
		bfs(u);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (dis[i] == v)
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}