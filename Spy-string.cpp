#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map/set
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//========================XXXXXXXXXXXXXXXX===========================
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 3e5 + 2;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int> >
#define all(x) x.begin(), x.end()
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	string cmp = a[0];
	rep(i, 0, m) {
		char cache = cmp[i];
		for(char j = 'a'; j <= 'z'; j++) {
			cmp[i] = j;
			bool isPoss = true;
			rep(k, 0, n) {
				int nonMatch = 0;
				rep(l, 0, m) {
					if(a[k][l] != cmp[l])
						nonMatch++;
				}
				if(nonMatch > 1) {
					isPoss = false;
					break;
				}
			}
			if(isPoss) {
				cout << cmp << "\n";
				return;
			}
		}
		cmp[i] = cache;
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}