#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 1000001

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//------------------------------------------------------------------
// To find the value of -> [ Sum of gcd(i, N) for all i from 1 to N ]
// In case of multiple queries, with the help of ETF.
//------------------------------------------------------------------

int phi[1000001];

void queriedPhi() {
	for (int i = 0; i < maxN; i++)
		phi[i] = i;

	for (int i = 2; i < maxN; i++) {
		if (phi[i] == i) {
			for (int j = i; j < maxN; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}

void solve() {
	int N;
	cin >> N;
	int ans = 0;

	for (int i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			int d1 = i;
			int d2 = N / i;

			ans += d1 * phi[N / d1];
			if (d1 != d2)
				ans += d2 * phi[N / d2];
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
	int q;
	cin >> q;
	queriedPhi();
	while (q--)
		solve();
	return 0;
}