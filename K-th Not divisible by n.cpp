#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

void solve2() {
	// Binary Search implementation
	ll n, k, ans;
	cin >> n >> k;
	ll lo = 1, hi = 2e9, mid, x;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		x = mid - (mid / n);
		if (x >= k) {
			if (mid % n != 0)
				ans = mid;
			hi = mid;
		}
		else
			lo = mid + 1;
	}
	cout << ans << "\n";
}

void solve() {
	// Simple mathematics implementation
	ll n, k, ans;
	cin >> n >> k;
	ans = k + (k / (n - 1));
	if (ans % n == 0)
		ans--;
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
		solve2();
	return 0;
}