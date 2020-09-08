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
#define maxN 10006

vector<int> ar[maxN], inEdge(maxN), topSort;
int n;

void kahn(int node) {
	// declaring a min-heap pq
	priority_queue<int, vector<int>, greater<int> > pq;
	rep(i, 1, n + 1) {
		if (inEdge[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int curr = pq.top();
		topSort.pb(curr);
		pq.pop();

		for (int child : ar[curr]) {
			inEdge[child]--;
			if (inEdge[child] == 0)
				pq.push(child);
		}
	}
	if (topSort.size() != n)
		cout << "Sandro fails.\n";
	else {
		for (int order : topSort)
			cout << order << " ";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	cin >> n >> m;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
		inEdge[v]++;
	}
	kahn(1);
	return 0;
}