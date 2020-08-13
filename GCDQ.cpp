#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define N 100001

int pre[N], suff[N];

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

void preCompute(vector<int> &A, int s) {
	pre[0] = A[0];
	for (int i = 1; i < s; i++)
		pre[i] = gcd(A[i], pre[i - 1]);
	suff[s - 1] = A[s - 1];
	for (int i = s - 2; i >= 0; i--)
		suff[i] = gcd(A[i], suff[i + 1]);
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	preCompute(a, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == 1) cout << suff[r];
		else if (r == n) cout << pre[l - 2];
		else cout << gcd(pre[l - 2], suff[r]);
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