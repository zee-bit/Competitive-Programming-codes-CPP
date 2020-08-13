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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int x;
			cin >> x;
			a[x] = (a[x] == 1) ? 0 : 1;
		}
		else {
			int l, r;
			cin >> l >> r;
			if (a[r] == 1)
				cout << "ODD\n";
			else
				cout << "EVEN\n";
		}
	}
	return 0;
}