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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	//>>>>>Intuitive approach
	// if (n == 0)
	// 	cout << "1\n";
	// else {
	// 	int d[] = {8, 4, 2, 6};
	// 	n--;
	// 	n %= 4;
	// 	cout << d[n] << "\n";
	// }

	//>>>>>Using Binary Exponentiation
	ll ans = 1, a = 8, p = 10;
	while (n) {
		if (n % 2)
			ans = (ans * a) % p;
		a = (a * a) % p;
		n /= 2;
	}
	cout << ans << "\n";
	return 0;
}
