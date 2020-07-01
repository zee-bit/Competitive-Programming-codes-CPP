#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, c , t;
	cin >> h >> c >> t;

	if ((h + c) / 2 >= t) {
		cout << 2 << "\n";
		return;
	}
	else if (t >= h) {
		cout << 1 << "\n";
		return;
	}
	else {
		double crit = (t - c) / (2.0 * t - h - c);
		double x1 = ceil(crit), x2 = floor(crit);
		//double ansX = round(crit);
		//if (ansX == 1)
		//	ansX = ceil(crit);
		double y1 = (x1 * h + (x1 - 1) * c) / (2 * x1 - 1);
		double y2 = (x2 * h + (x2 - 1) * c) / (2 * x2 - 1);

		if (y2 - t <= t - y1)
			cout << (2 * x2 - 1) << "\n";
		else
			cout << (2 * x1 - 1) << "\n";
		//cout << (2 * ansX - 1) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}

