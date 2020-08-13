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

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

void solve() {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k, mx = 0, l;
	string s;
	cin >> s >> k;
	l = s.length() + 1;
	vector<int> w(26);
	rep(i, 0, 26) {
		cin >> w[i];
		mx = max(mx, w[i]);
	}
	ll ans = 0;
	rep(i, 1, l) {
		ans += w[s[i - 1] - 'a'] * i;
	}
	rep(i, l, l + k) {
		ans += mx * i;
	}
	cout << ans << "\n";
	return 0;
}