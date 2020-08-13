#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 40001

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};
bool prime[maxN];

// Segmented Sieve Approach
void sieve() {
	prime[0] = 0, prime[1] = 0;
	for (ll i = 2; i < maxN; i++) prime[i] = 1;
	for (ll i = 2; i < maxN; i++) {
		if (prime[i]) {
			for (ll j = i * i; j < maxN; j += i)
				prime[j] = false;
		}
	}
}

void solve() {
	ll l, r;
	cin >> l >> r;
	vector<bool> rangePrime(r - l + 1, 1);
	for (ll i = 2; i < maxN; i++) {
		if (prime[i]) {
			for (ll j = l; j <= r;) {
				if (j % i == 0 && j != i) {
					rangePrime[j - l] = false;
					j += i;
				}
				else j++;
			}
		}
	}
	for (ll i = 0; i < r - l + 1; i++) {
		if (rangePrime[i] && (i + l != 1))
			cout << i + l << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	sieve();
	cin >> t;
	while (t--)
		solve();
	return 0;
}