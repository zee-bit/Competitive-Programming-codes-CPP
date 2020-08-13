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
#define maxN 100001

vector<int> ar[maxN];
vector<char> ch(maxN);
vector<string> st(maxN);

string dfs(int node, int par) {
	string s = "";
	for (int child : ar[node]) {
		if (child == par)
			continue;
		s += dfs(child, node);
	}
	s += ch[node];
	st[node] = s;
	return st[node];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	rep(i, 1, n + 1) {
		cin >> ch[i];
	}
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	string full = dfs(1, 0);
	// rep(i, 1, n + 1) {
	// 	cout << st[i] << "\n";
	// }
	while (q--) {
		int x, ans = 0;
		string inp;
		cin >> x >> inp;
		vector<int> f1(27, 0), f2(27, 0);
		//cout << st[x] << "\n";
		rep(i, 0, int(st[x].length()))
		f1[st[x][i] - 'a']++;
		rep(i, 0, int(inp.length()))
		f2[inp[i] - 'a']++;
		rep(i, 0, 27) {
			if (f2[i] > 0) {
				if (f1[i] < f2[i])
					ans += f2[i] - f1[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}