#include <iostream>
#include <cmath>
using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
// 	// for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		float prod = n * m;
		cout << int(ceil(prod / 2.0)) << "\n";
	}
	return 0;
}
