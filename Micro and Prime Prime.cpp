#include <bits/stdc++.h>
using namespace std;

bool notprime[1000001];
int prefPrime[1000001];
void prime() {
	notprime[0] = 1, notprime[1] = 1;
	for (int i = 2; i * i <= 1000000; i++) {
		if (!notprime[i]) {
			for (int j = i * i; j <= 1000000; j += i)
				notprime[j] = 1;
		}
	}
	int cnt = 0;
	prefPrime[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (!notprime[i])
			cnt++;
		if (!notprime[cnt])
			prefPrime[i] = 1;
		else
			prefPrime[i] = 0;
		prefPrime[i] += prefPrime[i - 1];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	prime();
	int t;
	cin >> t;
	while (t--) {
		int l, r, ans = 0;
		cin >> l >> r;
		ans = prefPrime[r] - prefPrime[l - 1];
		cout << ans << "\n";
	}
	return 0;
}