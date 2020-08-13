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

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	vector<vector<int> > dp(n, vector<int> (m, 0));
	int mn = INT_MAX, an;
	rep(i, 0, n)
	cin >> a[i];
	rep(i, 0, m)
	cin >> b[i];
	rep(i, 0, n) {
		rep(j, 0, m) {
			dp[i][j] = min(a[i] & b[j];
		}
	}
	rep(i, 0, n) {
		rep(j, 0, m) {
			mn = min()
		}
	}
	return 0;
}