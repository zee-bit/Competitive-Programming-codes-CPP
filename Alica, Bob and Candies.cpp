#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int a = 0, b = 0, moves = 0, p1 = 0, p2 = n - 1, nowSum = 0, lastSum = 0;
	while (p1 <= p2) {
		if (moves % 2 == 0) {
			nowSum = 0;
			while (p1 <= p2 && nowSum <= lastSum) {
				nowSum += arr[p1];
				p1++;
			}
			a += nowSum;
			lastSum = nowSum;
			moves++;
		}
		else {
			nowSum = 0;
			while (p1 <= p2 && nowSum <= lastSum) {
				nowSum += arr[p2];
				p2--;
			}
			b += nowSum;
			lastSum = nowSum;
			moves++;
		}
	}
	cout << moves << " " << a << " " << b << "\n";
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