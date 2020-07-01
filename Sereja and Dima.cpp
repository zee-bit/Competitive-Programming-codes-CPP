#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sumS = 0, sumD = 0, p1 = 0, p2 = n - 1;
	while (p1 <= p2) {
		if (a[p1] >= a[p2]) {
			sumS += a[p1];
			p1++;
		}
		else {
			sumS += a[p2];
			p2--;
		}
		if (p1 <= p2) {
			if (a[p1] >= a[p2]) {
				sumD += a[p1];
				p1++;
			}
			else {
				sumD += a[p2];
				p2--;
			}
		}
	}
	// if (p1 == 0)
	// 	sumS += a[0];
	// if (p2 == n - 1)
	// 	sumS += a[n - 1];
	cout << sumS << " " << sumD << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}