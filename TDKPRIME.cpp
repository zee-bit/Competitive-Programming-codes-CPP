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

bool prime[87000008];
int kprime[5000001];

void sieve() {
	for (int i = 0; i <= 87000007; i++)
		prime[i] = true;
	prime[0] = false, prime[1] = false;
	for (int i = 2; i * i <= 87000007; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 87000007; j += i)
				prime[j] = false;
		}
	}
}

void findPrime() {
	int j = 1;
	kprime[0] = -1;
	for (int i = 2; i <= 87000007 && j <= 5000000; i++)
		if (prime[i]) {
			kprime[j] = i;
			j++;
		}
}

void solve() {
	int n;
	cin >> n;
	cout << kprime[n] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	sieve();
	findPrime();
	cin >> t;
	while (t--)
		solve();
	return 0;
}