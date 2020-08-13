#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//==========================XXXXXXXXXXXXXXXX=============================

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define maxN 100001

void solve() {

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
	vector<int> a(maxN, 0);
	rep(i, 0, n) {
		int x;
		cin >> x;
		a[x]++;
	}
	int rect = 0, sqr = 0;
	rep(i, 1, maxN) {
		rect += (a[i] / 2);
		sqr += (a[i] / 4);
	}
	int q, x;
	char c;
	cin >> q;
	while (q--) {
		cin >> c >> x;
		if (c == '+') {
			rect -= (a[x] / 2);
			sqr -= (a[x] / 4);
			a[x]++;
			rect += (a[x] / 2);
			sqr += (a[x] / 4);
		}
		else {
			rect -= (a[x] / 2);
			sqr -= (a[x] / 4);
			a[x]--;
			rect += (a[x] / 2);
			sqr += (a[x] / 4);
		}
		if (rect >= 4 && sqr >= 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}