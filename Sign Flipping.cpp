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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (a[i] < 0)
				a[i] = -a[i];
		}
		else {
			if (a[i] > 0)
				a[i] = -a[i];
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
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