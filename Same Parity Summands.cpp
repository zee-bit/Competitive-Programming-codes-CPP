#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

void solve() {
	int n, k;
	cin >> n >> k;
	int caseOdd = k - 1, caseEven = 2 * (k - 1);
	if (caseEven >= n && caseOdd >= n)
		cout << "NO\n";
	else if (caseEven >= n) {
		if ((n - caseOdd) % 2 == 0)
			cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 1; i < k; i++)
				cout << "1 ";
			cout << n - caseOdd << "\n";
		}
	}
	else {
		int remOdd = n - caseOdd, remEven = n - caseEven;
		if (remOdd & 1) {
			cout << "YES\n";
			for (int i = 1; i < k; i++)
				cout << "1 ";
			cout << remOdd << "\n";
		}
		else if (remEven % 2 == 0) {
			cout << "YES\n";
			for (int i = 1; i < k; i++)
				cout << "2 ";
			cout << remEven << "\n";
		}
		else
			cout << "NO\n";
	}
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