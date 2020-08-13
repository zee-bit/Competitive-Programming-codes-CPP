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
	int a, b, c, r, del;
	cin >> a >> b >> c >> r;
	if (a > b)
		swap(a, b);
	if (c + r <= a || c - r >= b)
		del = 0;
	else
		del = min(b, c + r) - max(a, c - r);
	cout << b - a - del << "\n";
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