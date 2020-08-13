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
#define repr(i, a, b) for(ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, mx = 0, lo = 0, hi = 1, pf;
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	bool ignore = true;
	while (hi < n) {
		if (a[hi - 1] < a[hi] || ignore) {
			if (a[hi - 1] >= a[hi]) {
				ignore = false;
				pf = hi;
			}
			hi++;
		}
		else {
			mx = max(mx, hi - lo);
			lo = pf;
			ignore = true;
		}
	}
	mx = max(mx, hi - lo);
	cout << mx;
	return 0;
}