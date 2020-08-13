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
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	cout << x << " " << y << "\n";

	// if(y != 1)
	// cout << x << " " << 1 << "\n";
	// if(x != 1) {
	// 	cout << 1 << " " << y << "\n";
	// }
	for (int i = m; i >= 1; i--) {
		if (i != y)
			cout << x << " " << i << "\n";
	}
	int k = 1;
	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		if (k & 1) {
			for (int j = 1; j <= m; j++) {
				cout << i << " " << j << "\n";
			}
			k++;
		} else {
			for (int j = m; j >= 1; j--) {
				cout << i << " " << j << "\n";
			}
			k++;
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
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}