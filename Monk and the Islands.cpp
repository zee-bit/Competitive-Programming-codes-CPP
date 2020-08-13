#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back

vector<int> a[10001], dis(10001);
bool vis[10001];

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = true;
	dis[src] = 0;

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
	int t, n, m, u, v;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			vis[i] = false;
			a[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			a[u].pb(v);
			a[v].pb(u);
		}
		bfs(1);
		cout << dis[n] << "\n";
	}
}