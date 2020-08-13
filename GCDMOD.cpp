#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

ll power(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n % 2)
			res = ((res % m) * (a % m)) % m;
		a = ((a % m) * (a % m)) % m;
		n /= 2;
	}
	return res;
}

void solve() {
	ll a, b, n;
	cin >> a >> b >> n;

	if (a == b)
		cout << (power(a, n, mod) + power(b, n, mod)) % mod << "\n";
	else {
		ll candidate = 1, num = a - b;
		for (ll i = 1; i * i <= num; i++) {
			if (num % i == 0) {
				ll chk = (power(a, n, i) + power(b, n, i)) % i;
				if (chk == 0) {
					candidate = max(candidate, i);
				}
				chk = (power(a, n, num / i) + power(b, n, num / i)) % (num / i);
				if (chk == 0) {
					candidate = max(candidate, num / i);
				}
			}
		}
		cout << candidate % mod << "\n";
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