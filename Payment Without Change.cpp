#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define for(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

void solve() {
	ll a, b, n, s;
	cin >> a >> b >> n >> s;
	if ((a * n + b) < s)
		cout << "No\n";
	else {
		ll x = min(a, s / n);
		s -= n * x;
		if (b >= s)
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
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}