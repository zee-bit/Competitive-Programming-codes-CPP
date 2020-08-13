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

ll height[30002];
void solvePyr() {
	height[0] = 0;
	for (ll i = 1; i <= 30000; i++)
		height[i] = (2 * i) + (i - 1) + height[i - 1];
}

void solve() {
	int n, ans = 0;
	cin >> n;
	while (n > 1) {
		int l = 1, h = 30000, mid, thr;
		while (l <= h) {
			mid = l + (h - l) / 2;
			if (height[mid] <= n) {
				thr = height[mid];
				l = mid + 1;
			}
			else
				h = mid - 1;
		}
		ans += n / thr;
		n = n % thr;
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
	solvePyr();
	cin >> t;
	while (t--)
		solve();
	return 0;
}