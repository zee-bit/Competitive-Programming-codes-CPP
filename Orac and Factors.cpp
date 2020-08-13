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

int smallestDiv(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return i;
	}
	return n;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		cout << n + 2 * k << "\n";
	}
	else {
		int d = smallestDiv(n);
		n += d;
		cout << n + 2 * (k - 1) << '\n';
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