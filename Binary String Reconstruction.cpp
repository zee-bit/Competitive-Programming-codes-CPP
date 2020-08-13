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

void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	if (n2 == 0) {
		if (n1 > 0) {
			rep(i, n1 + 1)
			cout << "0";
		}
		if (n3 > 0) {
			rep(i, n3 + 1)
			cout << "1";
		}
		cout << "\n";
	}
	else {
		string z = "", o = "";
		rep(i, n1)
		z += '0';
		rep(i, n3)
		o += '1';
		cout << "1" << o << "0" << z;
		rep(i, n2 - 1) {
			if (i % 2 == 0)
				cout << "1";
			else
				cout << "0";
		}
		cout << "\n";
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