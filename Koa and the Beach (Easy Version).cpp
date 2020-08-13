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
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> d(n + 1), p(2 * k);
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 0; i < k; i++) {
		p[i] = i;
		p[i + k] = k - i;
	}
	int t = 1;
	for (int i = 1; i <= (2 * k); i++) {
		t = i;
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			int depth = d[j] + p[t % (2 * k)];
			t++;
			if (depth > l) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
			return;
		}
	}
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