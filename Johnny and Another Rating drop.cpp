#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// METHOD 1 : When n = 2^k, answer is 2n-1, so for any arbitrary n, the answer
// would be 2n-(number of set bits in n)
void solve() {
	ll n;
	cin >> n;
	int setBits = __builtin_popcountll(n);
	cout << 2 * n - setBits << "\n";
}

// METHOD 2 : At every interval of n/2, our answer increases by n, so we could
// just keep on adding n and dividing n by 2 at every iteration till it equals 1
void solve2() {
	ll n;
	cin >> n;
	ll ans = 1;
	while (n != 1) {
		ans += n;
		n /= 2;
	}
	cout << ans << "\n";
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
		solve2();
	return 0;
}