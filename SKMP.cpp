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

void solve() {
	string s, p, s1 = "", s2 = "";
	cin >> s >> p;
	int ls = s.length(), lp = p.length();
	vector<int> letts(26, 0), lettp(26, 0), ans1, ans2;
	rep(i, 0, ls) {
		letts[s[i] - 'a']++;
	}
	rep(i, 0, lp) {
		lettp[p[i] - 'a']++;
	}
	rep(i, 0, 26) {
		int r = letts[i] - lettp[i];
		rep(j, 0, r) {
			ans1.pb('a' + i);
			s1 += char('a' + i);
			ans2.pb('a' + i);
			s2 += char('a' + i);
			letts[i]--;
		}
	}
	int thres = p[0];
	int pos1 = upper_bound(all(ans1), thres) - ans1.begin();
	int pos2 = lower_bound(all(ans2), thres) - ans2.begin();
	s1.insert(pos1, p);
	s2.insert(pos2, p);
	if (s1 >= s2)
		cout << s2 << "\n";
	else
		cout << s1 << '\n';
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