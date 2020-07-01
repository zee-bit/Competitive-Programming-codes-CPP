#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359

void solve() {
	int n;
	cin >> n;
	double theta = (360.0 / (4.0 * n));
	double halfLength = 0.5 / tan(theta * PI / 180.0);
	printf("%.9f\n", 2.0 * halfLength);
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