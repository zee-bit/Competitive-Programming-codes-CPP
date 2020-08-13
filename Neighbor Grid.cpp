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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int chk = 0;
			if (i - 1 >= 0) {
				if (a[i - 1][j] == 0)
					a[i - 1][j] = 1;
				chk++;
			}
			if (j - 1 >= 0) {
				if (a[i][j - 1] == 0)
					a[i][j - 1] = 1;
				chk++;
			}
			if (i + 1 < n) {
				if (a[i + 1][j] == 0)
					a[i + 1][j] = 1;
				chk++;
			}
			if (j + 1 < m) {
				if (a[i][j + 1] == 0)
					a[i][j + 1] = 1;
				chk++;
			}
			if (a[i][j] > chk) {
				cout << "NO\n";
				return;
			}
			else
				a[i][j] = chk;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
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