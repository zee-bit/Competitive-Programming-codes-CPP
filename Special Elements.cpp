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
	int n;
	cin >> n;
	vector<int> a(n), prefix(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	prefix[0] = 0;
	prefix[1] = a[0];
	for (int i = 1; i < n; i++)
		prefix[i + 1] = a[i] + prefix[i];
	int l = 0, h = 2, ans = 0, x;
	for (int i = 0; i < n; i++) {
		l = 0, h = 2, x = a[i];
		while (h <= n && l <= n) {
			if (prefix[h] - prefix[l] == x) {
				ans++;
				break;
			}
			else if (prefix[h] - prefix[l] > x) {
				l++;
				if (h == l + 1)
					h++;
			}
			else
				h++;
		}
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