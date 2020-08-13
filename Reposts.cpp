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

void Lower(string &str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, mx = 1;
	cin >> n;
	string r, ch, par;
	map<string, int> dp;
	dp["polycarp"] = 1;
	for (int i = 0; i < n; i++) {
		cin >> ch >> r >> par;
		Lower(ch), Lower(par);
		dp[ch] = dp[par] + 1;
		mx = max(mx, dp[ch]);
	}
	cout << mx << "\n";
	return 0;
}