#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007

int fact[1000001];

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

//--------------------------------------------------------------
// 				   				       (n!)%mod
//To calculate -> C(n, r)%mod = -------------------------
//              		  	    (r!)%mod * ((n - r)!)%mod
//--------------------------------------------------------------

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b /= 2;
	}
	return res;
}

int C(int n, int r) {
	if (r > n) return 0;

	int res = fact[n];

	// From Fermat's Little Theorem
	// (1/a) = a^(m - 2) (mod m)
	res = (res * 1LL * power(fact[r], mod - 2)) % mod;
	res = (res * 1LL * power(fact[n - r], mod - 2)) % mod;

	return res;
}

void solve() {
	int n, r;
	cin >> n >> r;
	// Storing all the factorials of
	// numbers till 1e6 modulo.[fact[n] = (n!)%mod]
	cout << C(n, r) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		fact[i] = (fact[i - 1] * 1LL * i) % mod;
	cin >> t;
	while (t--)
		solve();
	return 0;
}