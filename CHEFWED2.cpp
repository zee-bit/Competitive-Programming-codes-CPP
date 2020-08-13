#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//==========================XXXXXXXXXXXXXXXX=============================

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	vector<vector<int> > cache(n, vector<int> (n, 0));
	vector<int> m(101, 0);
	rep(i, 0, n) {
		rep(j, i, n) {
			if (j == 0)	{
				m[a[j]]++;
				continue;
			}
			cache[i][j] = cache[i][j - 1];
			if (m[a[j]] > 0) {
				if (m[a[j]] == 1)
					cache[i][j] ++;
				cache[i][j]++;
			}
			m[a[j]]++;
		}
		rep(j, 0, 101)
		m[j] = 0;
	}
	int mx_tables = 101, final_ans = INT_MAX;
	vector<vector<int> > dp(mx_tables, vector<int> (n + 2, 0));
	rep(i, 1, n + 1) {
		dp[1][i] = cache[0][i - 1];
	}
	rep(i, 2, mx_tables) {
		rep(j, 2, n + 1) {
			int mn = INT_MAX;
			rep(l, 1, j) {
				mn = min(mn, dp[i - 1][l] + cache[l][j - 1]);
			}
			dp[i][j] = mn;
		}
	}
	// rep(i, 1, 5) {
	// 	rep(j, 1, n + 1) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	rep(t, 1, mx_tables) {
		final_ans = min(final_ans, int(t * k + dp[t][n]));
	}
	cout << final_ans << "\n";
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