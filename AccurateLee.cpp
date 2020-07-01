#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, first_one = 0;
	string s, ans = "";
	cin >> n >> s;
	// if (n == 1) {
	// 	cout << s << "\n";
	// 	return;
	// }

	// for (int i = n - 1; i >= 0; i--)
	// 	if (s[i] == '1')
	// 		ans = s[i] + ans;
	// 	else {
	// 		if (i == 0)
	// 			first_one = 0;
	// 		else
	// 			first_one = i + 1;
	// 		break;
	// 	}

	// for (int i = 0 ; i < first_one; i++)
	// 	if (s[i] == '0')
	// 		ans = s[i] + ans;
	// 	else {
	// 		ans = '0' + ans;
	// 		break;
	// 	}

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0' && i > 0) {
			first_one = i + 1;
			break;
		}
		ans = s[i] + ans;
	}
	for (int i = 0; i < first_one; i++) {
		if (s[i] == '1') {
			ans = '0' + ans;
			break;
		}
		ans = s[i] + ans;
	}

	cout << ans << "\n";
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