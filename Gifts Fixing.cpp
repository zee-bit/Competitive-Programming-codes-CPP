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

void solve() {
	int n, mina = INT_MAX , minb = INT_MAX;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		minb = min(minb, b[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mina && b[i] > minb)
			ans += max(a[i] - mina, b[i] - minb);
		else if (a[i] > mina && b[i] == minb)
			ans += a[i] - mina;
		else if (b[i] > minb && a[i] == mina)
			ans += b[i] - minb;
	}
	cout << ans << "\n";
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