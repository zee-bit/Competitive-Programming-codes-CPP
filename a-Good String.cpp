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

int calcAns(string &s, char c, int l, int r) {
	if (l == r)
		return s[l] != c;

	int a = 0, b = 0;
	int mid = (l + r + 1) / 2;

	for (int i = l; i < mid; i++)
		if (s[i] != c) a++;

	for (int i = mid; i <= r; i++)
		if (s[i] != c) b++;

	int ans = min(a + calcAns(s, c + 1, mid, r),
	              b + calcAns(s, c + 1, l, mid - 1));
	return ans;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;

	cout << calcAns(s, 'a', 0, n - 1) << "\n";
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