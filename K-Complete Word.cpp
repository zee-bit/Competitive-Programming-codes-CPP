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

int store[200007][26];

int calcAns(int a, int b) {
	int mx = 0, tot = 0;
	for (int i = 0; i < 26; i++) {
		tot += store[a][i] + store[b][i];
		mx = max(mx, store[a][i] + store[b][i]);
	}
	return tot - mx;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < 26; j++)
			store[i][j] = 0;

	for (int i = 0; i < n; i++) {
		store[i % k][s[i] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += calcAns(i, k - i - 1);
	}
	cout << ans / 2 << "\n";
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
	while (t--)
		solve();
	return 0;
}