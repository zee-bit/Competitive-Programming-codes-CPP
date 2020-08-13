#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return x + FIXED_RANDOM;
	}
};

vector<int> base26(string s) {
	vector<int> retVal(s.size() + 1);
	for (int i = 1; i <= int(s.size()); i++) {
		retVal[i] = s[i - 1] - 'a';
	}
	return retVal;
}

void solve() {
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	vector<int> l = base26(s), h = base26(t);

	// calculating sum in base26
	for (int i = k; i >= 0; i--) {
		l[i] += h[i];
		if (i) {
			l[i - 1] += l[i] / 26;
			l[i] %= 26;
		}
	}

	// dividing base26 by 2 i.e. [(l + h) / 2]
	for (int i = 0; i <= k; i++) {
		if (i + 1 <= k) {
			l[i + 1] += (l[i] % 2) * 26;
		}
		l[i] /= 2;
	}
	for (int i = 1; i <= k; i++)
		cout << char('a' + l[i]);
	cout << "\n";
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