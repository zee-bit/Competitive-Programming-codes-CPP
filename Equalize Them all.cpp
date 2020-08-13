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

void solve() {
	ll n, m = -1, id;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector<ll> fre(2e5, 0);
	for (ll i = 0; i < n; i++) {
		// if (fre[a[i]] == 0)
		// 	un++;
		++fre[a[i]];
		if (fre[a[i]] > m) {
			m = fre[a[i]];
			id = i;
		}
	}
	cout << n - m << "\n";
	for (ll i = id - 1; i >= 0; i--) {
		if (a[i] == a[id]) {
			id = i;
			continue;
		}
		else if (a[i] < a[id])
			cout << "1 " << i + 1 << " " << id + 1 << "\n";
		else
			cout << "2 " << i + 1 << " " << id + 1 << "\n";
		a[i] = a[id];
		id = i;
	}
	for (ll i = 0; i < n; i++) {
		if (a[i] == a[id]) {
			id = i;
			continue;
		}
		else if (a[i] < a[id])
			cout << "1 " << i + 1 << " " << id + 1 << "\n";
		else
			cout << "2 " << i + 1 << " " << id + 1 << "\n";
		a[i] = a[id];
		id = i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}