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

pair<int, int> findRange(vector<int> &arr) {
	int max = 0, idx = 0, n = arr.size();
	pair<int, int> ret = {0, 0};
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			if (i - idx > max) {
				max = i - idx;
				ret = {idx + 1, i};
			}
			idx = i + 1;
		}
	}
	if (n - idx > max) {
		ret = {idx + 1, n};
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		pair<int, int> get = findRange(a);
		int l = get.first;
		int r = get.second;
		if ((r - l + 1) & 1)
			a[(l + r) / 2 - 1] = i + 1;
		else
			a[(l + r - 1) / 2 - 1] = i + 1;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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