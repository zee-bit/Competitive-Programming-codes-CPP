#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(201, true), semiprime(201, false);

void sieve() {
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 200; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 200; j += i)
				prime[j] = false;
		}
	}
}

void semiPrimes() {
	sieve();
	for (int i = 6; i <= 200; i++) {
		for (int j = 2; j <= (i / 2); j++) {
			if (i % j == 0 && prime[j]) {
				int b = i / j;
				if (i % b == 0 && prime[b] && j != b) {
					semiprime[i] = true;
					break;
				}
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	semiPrimes();

	for (int i = 1; i <= n; i++) {
		int a = i, b = n - i;
		if (semiprime[a] && semiprime[b]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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