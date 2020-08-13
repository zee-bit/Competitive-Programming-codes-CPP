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

// void solve() {

// }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> is(100001, false);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		is[a[i]] = true;
	}
	vector<int> ans(n, -1);
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			ans[i] = a[i - 1];
			//is[a[i]] = true;
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			for (int j = k; j < 100001; j++) {
				if (is[j]  == 0) {
					ans[i] = j;
					is[j] = true;
					k = j + 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}