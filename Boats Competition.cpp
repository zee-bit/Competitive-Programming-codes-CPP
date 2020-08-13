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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(2 * n, 0);
	rep(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	int s = 0, ans = 0;
	for (int i = 2; i <= 2 * n; i++) {
		s = 0;
		for (int j = 1; 2 * j < i; j++) {
			s += min(cnt[j], cnt[i - j]);
		}
		if ( i % 2 == 0)
			s += cnt[i / 2] / 2;
		ans = max(s, ans);
	}
	cout << ans << "\n";
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