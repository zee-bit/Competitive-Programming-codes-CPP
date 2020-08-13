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
		return x + FIXED_RANDOM;
	}
};

void solve() {
	int a, b, c, d, x, y, x1, y1, x2, y2;
	cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
	int hor = x - a + b, ver = y - c + d;
	if (x1 <= hor && x2 >= hor && (x1 < x2 || a + b == 0))
		if (y1 <= ver && y2 >= ver && (y1 < y2 || c + d == 0))
			cout << "Yes\n";
		else
			cout << "No\n";
	else
		cout << "No\n";
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