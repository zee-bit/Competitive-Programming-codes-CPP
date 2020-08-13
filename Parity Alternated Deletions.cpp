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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, odd = 0, even = 0, k, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] & 1)
			odd++;
		else
			even++;
	}
	bool m = odd > even;
	k = max(odd, even) - min(odd, even) - 1;
	if (k <= 0)
		cout << "0\n";
	else {
		sort(a.begin(), a.end());
		for (int i = 0; i < n && k > 0; i++) {
			if ((a[i] & 1) && m) {
				ans += a[i];
				k--;
			}
			else if ((a[i] % 2 == 0) && !m) {
				ans += a[i];
				k--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}