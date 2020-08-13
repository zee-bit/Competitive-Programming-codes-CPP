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
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p1 = n, p2 = n;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			p1 = i;
			break;
		}
	}
	if (p1 == n) {
		cout << "0\n";
		return;
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] != i) {
			p2 = i;
			break;
		}
	}
	for (int i = p1; i <= p2; i++) {
		if (a[i] == i) {
			cout << "2\n";
			return;
		}
	}
	cout << "1\n";
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