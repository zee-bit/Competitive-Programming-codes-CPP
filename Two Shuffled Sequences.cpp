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
	int n, inc = 0;
	cin >> n;
	vector<int> a(n), cnt(200002, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	//sort(all(a));
	for (int i = 0; i <= 2e5; i++) {
		if (cnt[i] > 2) {
			cout << "NO\n";
			return;
		}
		else if (cnt[i] == 2)
			inc++;
	}
	cout << "YES\n";
	cout << inc << "\n";
	for (int i = 0; i <= 2e5; i++) {
		if (cnt[i] == 2)
			cout << i << " ";
	}
	cout << "\n";
	cout << n - inc << "\n";
	for (int i = 2e5; i >= 0; i--) {
		if (cnt[i] >= 1)
			cout << i << " ";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}