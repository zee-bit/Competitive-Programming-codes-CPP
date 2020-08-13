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
	vector<int> c(4);
	int mn = INT_MAX, z = 0;
	rep(i, 0, 3) {
		cin >> c[i];
		z += (c[i] % 2);
		mn = min(mn, c[i]);
	}
	cin >> c[3];
	z += c[3] % 2;
	if (z <= 1)
		cout << "Yes\n";
	else {
		if (mn >= 1) {
			rep(i, 0, 3)
			c[i]--;
			c[3]++;
		}
		int cnt = 0;
		rep(i, 0, 4) {
			if (c[i] & 1)
				cnt++;
		}
		if (cnt <= 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
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