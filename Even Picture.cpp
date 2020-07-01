//   |   |   |   |
//   -------------
//   |   | # | # |
//   -------------
//   | # | # | # |    -> For n = 1
//   -------------
//   | # | # |   |
//   -------------
//   |   |   |   |

#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
	int size = 3 * n + 4;
	cout << size << '\n';
	cout << "0 0\n1 0\n";
	for (int i = 1; i <= n; i++) {
		cout << i - 1 << " " << i << "\n";
		cout << i << " " << i << "\n";
		cout << i + 1 << " " << i << "\n";
	}
	cout << n << " " << n + 1 << "\n";
	cout << n + 1 << " " << n + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	solve(n);
	return 0;
}