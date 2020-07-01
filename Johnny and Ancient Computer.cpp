#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll powerOfTwo(ll n) {
	//return x && (!(x & (x - 1)));
	ll ret = 0;
	if (n > 0) {
		while (n % 2 == 0) {
			n /= 2;
			ret++;
		}
		if (n == 1)
			return ret;
	}
	if (n == 0 || n != 1)
		return -1;
}

void solve() {
	ll a, b, div;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << "\n";
		return;
	}
	if (a < b)
		swap(a, b);
	if (a % b != 0)
		cout << -1 << "\n";
	else {
		div = powerOfTwo(a / b);
		if (div != -1)
			cout << div / 3 + (div % 3 > 0) << "\n";
		else
			cout << -1 << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}