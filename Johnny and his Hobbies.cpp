#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n;
	unordered_set<int> a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
	}
	// vector<bool> vis(n, false);
	// unordered_set<int> newSet;
	for (int k = 1; k <= 1024; k++) {
		bool poss = true;
		for (auto it : a) {
			int ch = it ^ k;
			if (a.find(ch) == a.end()) {
				poss = false;
				break;
			}
		}
		if (poss) {
			cout << k << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
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


// Another solution by implementing a set or map using an array when the
// range of numbers are provided.

#include <bits/stdc++.h>
using namespace std;

const int N = 1025;

int n;
int in[N];
bool is[N];

bool check(int k) {
	for (int i = 1; i <= n; ++i)
		if (!is[in[i] ^ k])
			return false;
	return true;
}

void solve() {
	for (int i = 0; i < N; ++i)
		is[i] = false;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		is[in[i]] = true;
	}

	for (int k = 1; k < 1024; ++k)
		if (check(k)) {
			printf("%d\n", k);
			return;
		}

	puts("-1");
}

int main() {
	int cases;
	scanf("%d", &cases);

	while (cases--)
		solve();
	return 0;
}