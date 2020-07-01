#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll k, curr = 1, i = 0;
	cin >> k;
	vector <int> times(10, 1);

	while (curr < k) {
		curr /= times[i];
		times[i]++;
		curr *= times[i];
		i = (i + 1) % 10;
	}
	string part = "codeforces";
	for (i = 0; i < 10; i++) {
		while (times[i]--)
			cout << part[i];
	}
	return 0;
}