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
#define maxN 100001

vector<int> ar[maxN];
double sum;

void dfs(int node, int par, float prob) {
	sum += prob;
	for (int child : ar[node]) {
		if (child == par)
			continue;
		dfs(child, node, prob / (ar[node].size() - (node != 1)));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, u, v;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		ar[v].pb(u);
		ar[u].pb(v);
	}

	dfs(1, 0, 1);
	cout << setprecision(15) << sum - 1 << "\n";
	return 0;
}