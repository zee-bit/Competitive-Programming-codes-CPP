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

int mex(vector<int> a) {
	int l = a.size();
	vector<int> fre(l + 1, 0);
	for (int i = 0; i < l; i++)
		++fre[a[i]];
	for (int i = 0; i < l; i++)
		if (fre[i] == 0)
			return i;
	return l;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> moves;
	for (int i = 0; i < 2 * n; i++) {
		int m = mex(a);
		if (m == n) {
			for (int j = 0; j < n; j++) {
				if (a[j] != j) {
					a[j] = m;
					moves.pb(j + 1);
					break;
				}
			}
		}
		else {
			a[m] = m;
			moves.pb(m + 1);
		}
	}
	cout << moves.size() << "\n";
	for (int i = 0; i < int(moves.size()); i++)
		cout << moves[i] << " ";
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