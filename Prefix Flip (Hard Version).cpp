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
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "0\n";
		return;
	}
	if (n == 1) {
		if (a == b) {
			cout << "0\n";
			return;
		}
		else {
			cout << "1 1\n";
			return;
		}
	}
	vector<int> movesA, movesB;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1])
			movesA.pb(i + 1);
	}

	for (int i = 0; i < n - 1; i++) {
		if (b[i] != b[i + 1])
			movesB.pb(i + 1);
	}

	if (a[n - 1] != b[n - 1])
		movesA.pb(n);

	cout << movesB.size() + movesA.size() << " ";
	for (int i = 0; i < int(movesA.size()); i++)
		cout << movesA[i] << " ";
	for (int i = int(movesB.size() - 1); i >= 0; i--)
		cout << movesB[i] << " ";
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