#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 100001

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};
int cntKPrime[maxN], dp[6][maxN];

void preCompute() {
	for (int i = 0; i < maxN; i++) cntKPrime[i] = 0;
	for (int i = 2; i < maxN; i++) {
		if (cntKPrime[i] == 0) {
			for (int j = i; j < maxN; j += i)
				cntKPrime[j]++;
		}
	}
	for (int i = 1; i <= 5; i++) {
		dp[i][1] = 0;
		for (int j = 2; j < maxN; j++)
			dp[i][j] = dp[i][j - 1] + (cntKPrime[j] == i);
	}
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	cout << dp[k][b] - dp[k][a - 1] << "\n";
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
	preCompute();
	while (t--)
		solve();
	return 0;
}