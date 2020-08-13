#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

map<ll, ll> primeFactors;
ll totalFactors;

void primeFactorization(ll n) {
	totalFactors = 1;
	for (ll i = 2; i * i <= n; i++)	 {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0)  {
				n /= i;
				cnt++;
			}
			primeFactors[i] = cnt;
			totalFactors *= (cnt + 1);
		}
	}
	if (n > 1) {
		primeFactors[n] = 1;
		totalFactors *= 2;
	}
}

void solve() {
	ll n, q, k, t;
	cin >> n >> q;
	primeFactorization(n);
	while (q--) {
		cin >> t >> k;
		if (t == 1) {
			ll res = 1;
			for (auto i : primeFactors) {
				ll cnt = 0;
				while (k % i.first == 0) {
					cnt++;
					k /= i.first;
				}
				res *= min(i.second, cnt) + 1;
			}
			cout << res << "\n";
		}
		else if (t == 2) {
			ll res = 1;
			for (auto i : primeFactors) {
				ll cnt = 0;
				while (k % i.first == 0) {
					cnt++;
					k /= i.first;
				}
				if (cnt > i.second) {
					res = 0;
					break;
				}
				res *= (i.second - cnt + 1);
			}
			if (k > 1) res = 0;
			cout << res << "\n";
		}
		else {
			ll res = 1;
			for (auto i : primeFactors) {
				ll cnt = 0;
				while (k % i.first == 0) {
					cnt++;
					k /= i.first;
				}
				if (cnt > i.second) {
					res = 0;
					break;
				}
				res *= (i.second - cnt + 1);
			}
			if (k > 1) res = 0;
			cout << totalFactors - res << "\n";
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
	solve();
	return 0;
}