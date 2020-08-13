#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 1000001
#define mod 1000000009

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

ll scores[maxN];
void calcScore() {
	scores[0] = 1, scores[1] = 0, scores[2] = 1;
	for (int i = 3; i < maxN; i++)
		scores[i] += (scores[i - 2] + scores[i - 3]) % mod;
}

void solve() {
	ll x;
	cin >> x;
	cout << scores[x] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	calcScore();
	cin >> t;
	while (t--)
		solve();
	return 0;
}