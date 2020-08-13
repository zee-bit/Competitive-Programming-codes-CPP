#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define n 51
#define mod 1000000007

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};
ll A[n][n], I[n][n];

void mul(ll a[][n], ll b[][n], ll dim) {
	ll res[n][n];
	for (ll i = 0; i < dim; i++) {
		for (ll j = 0; j < dim; j++) {
			res[i][j] = 0;
			for (ll k = 0; k < dim; k++)
				res[i][j] = ((res[i][j] % mod) + ((a[i][k] * b[k][j]) % mod)) % mod;
		}
	}

	for (ll i = 0; i < dim; i++) {
		for (ll j = 0; j < dim; j++) {
			a[i][j] = res[i][j];
		}
	}
}

// void power(ll a[][n], ll dim, ll pow) {
// 	for (ll i = 0; i < dim; i++) {
// 		for (ll j = 0; j < dim; j++) {
// 			if (i == j)
// 				I[i][j] = 1;
// 			else
// 				I[i][j] = 0;
// 		}
// 	}

// 	while (pow) {
// 		if (pow % 2)
// 			mul(I, a, dim), pow--;
// 		else
// 			mul(a, a, dim), pow /= 2;
// 	}

// 	for (ll i = 0; i < dim; i++) {
// 		for (ll j = 0; j < dim; j++) {
// 			a[i][j] = I[i][j];
// 		}
// 	}
// }

void solve() {
	ll p, m;
	cin >> m >> p;

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	// power(A, m, p);

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < m; j++) {
			if (i == j)
				I[i][j] = 1;
			else
				I[i][j] = 0;
		}
	}

	while (p) {
		if (p % 2)
			mul(I, A, m), p--;
		else
			mul(A, A, m), p /= 2;
	}

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < m; j++) {
			A[i][j] = I[i][j];
		}
	}

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < m; j++) {
			cout << A[i][j] << " ";
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