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

int maxDigs(int power) {
	int ans = 0;
	if (power % 9 != 0)
		ans++;
	ans += (power / 9);
	return ans;
}

void solve() {
	int pc, pr, dc, dr;
	cin >> pc >> pr;
	dc = maxDigs(pc);
	dr = maxDigs(pr);
	if (dc >= dr)
		cout << "1 " << dr << "\n";
	else
		cout << "0 " << dc << "\n";
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