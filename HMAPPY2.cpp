#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, a , b, k;
	cin >> n >> a >> b >> k;
	ll ans = (n / a) + (n / b);
	ll x = (a * b) / (__gcd(a, b));
	ans -= 2 * (n / x);
	if (ans >= k)
		cout << "Win\n";
	else
		cout << "Lose\n";
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