#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}

void solve() {
	int n;
	cin >> n;
	if (n == 1)
		cout << "FastestFinger\n";
	else if (n & 1 || n == 2)
		cout << "Ashishgup\n";
	else {
		if ((n & (n - 1)) == 0)
			cout << "FastestFinger\n";
		else if (n % 4 != 0 && isPrime(n / 2))
			cout << "FastestFinger\n";
		else
			cout << "Ashishgup\n";
	}
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