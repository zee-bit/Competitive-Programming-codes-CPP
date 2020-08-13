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

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define inf INT_MAX
#define ninf INT_MIN

//==========================XXXXXXXXXXXXXXXX=============================


void solve() {
	int n, k, final_ans = inf, mx_tables = 1;
	cin >> n >> k;
	vector<int> a(n), f(101, 0), brkpnts, suff(n + 1, 0), pre(n + 1, 0);
	rep(i, 0, n) {
		cin >> a[i];
		f[a[i]]++;
	}
	vector<int> cntSuf(101, 0), cntPre(101, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (cntSuf[a[i]] == 0) {
			suff[i] = suff[i + 1];
			cntSuf[a[i]]++;
		}
		else if (cntSuf[a[i]] == 1) {
			cntSuf[a[i]]++;
			suff[i] = suff[i + 1] + cntSuf[a[i]];
		}
		else {
			cntSuf[a[i]]++;
			suff[i] = suff[i + 1] + 1;
		}
	}
	cntPre[a[0]]++;
	for (int i = 1; i < n; i++) {
		if (cntPre[a[i]] == 0) {
			pre[i] = pre[i - 1];
			cntPre[a[i]]++;
		}
		else if (cntPre[a[i]] == 1) {
			cntPre[a[i]]++;
			pre[i] = pre[i - 1] + cntPre[a[i]];
		}
		else {
			cntPre[a[i]]++;
			pre[i] = pre[i - 1] + 1;
		}
	}

	int d = 0;
	rep(i, 1, 101) {
		if (f[i] > 1)
			d += f[i];
	}

	int ch_ans = 0;
	unordered_set<int> s;
	rep(i, 0, n) {
		if (s.count(a[i])) {
			mx_tables++;
			ch_ans = mx_tables * k + suff[i];
			final_ans = min(final_ans, ch_ans);
			s.clear();
			s.insert(a[i]);
		} else {
			s.insert(a[i]);
		}
	}
	s.clear();
	mx_tables = 1;
	int ch2;
	for (int i = n - 1; i >= 0; i--) {
		if (s.count(a[i])) {
			mx_tables++;
			ch_ans = mx_tables * k + pre[i];
			final_ans = min(final_ans, ch_ans);
			ch2 = 2 * k + pre[i] + suff[i + 1];
			final_ans = min(final_ans, ch2);
			s.clear();
			s.insert(a[i]);
		} else {
			s.insert(a[i]);
		}
	}
	final_ans = min(final_ans, mx_tables * k);
	final_ans = min(final_ans, d + k);
	//if (k == 1 || k < d) {cout << final_ans << "\n"; return;}
	cout << final_ans << "\n";
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