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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	vector<ll> a(n), suffix(n), cache(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	suffix[n - 1] = a[n - 1];
	for (ll i = n - 2; i >= 0; i--)
		suffix[i] = __gcd(suffix[i + 1], a[i]);
	for (ll i = 0; i < n - 1; i++)
		cache[i] = (a[i] * suffix[i + 1]) / __gcd(a[i], suffix[i + 1]);
	ll ans = cache[0];
	for (ll i = 1; i < n - 1; i++)
		ans = __gcd(ans, cache[i]);
	cout << ans << '\n';
	return 0;
}