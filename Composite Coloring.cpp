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

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), ans(n, -1);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int pr[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, col = 1;
	bool isDiv;

	for (int i = 0; i < 11; i++) {
		isDiv = false;
		for (int j = 0; j < n; j++) {
			if (ans[j] > -1)
				continue;
			else {
				if (a[j] % pr[i] == 0) {
					ans[j] = col;
					isDiv = true;
				}
			}
		}
		if (isDiv)
			col++;
	}
	cout << col - 1 << "\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
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