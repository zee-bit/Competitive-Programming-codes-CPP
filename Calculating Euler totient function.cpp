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
#define maxN 1000001

int phi[maxN];

// O(Nlog(logN)) for multiple queries
void queriedETF() {
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


// O(sqrt(N)) NOT for multiple queries
void ETF() {
	ll n;
	cin >> n;
	ll res = n;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res *= (i - 1);
			res /= i;

			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1) {
		res *= (n - 1);
		res /= n;
	}

	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n;
	cin >> t;
	queriedETF();
	while (t--) {
		cin >> n;
		cout << phi[n] << "\n";
	}
	return 0;
}