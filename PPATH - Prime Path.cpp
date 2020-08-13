#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// unhackable custom hash for unordered_map
// Credits : neil
struct custom_hash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};

//==============================================XXXXXXXXXXXXXXXX==================================================
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> ar[100001], prime, dis(100001);
bool vis[100001];

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isValid(int a, int b) {
	int cnt = 0;
	while (a > 0) {
		if (a % 10 != b % 10)
			cnt++;
		a /= 10;
		b /= 10;
	}
	if (cnt == 1)
		return true;
	else
		return false;
}

void buildGraph() {
	// Building primes
	for (int i = 1000; i <= 9999; i++) {
		if (isPrime(i))
			prime.pb(i);
	}
	// Building graph of primes differ only in one place
	for (int i = 0; i < int(prime.size()); i++) {
		for (int j = i + 1; j < int(prime.size()); j++) {
			int p = prime[i], q = prime[j];
			if (isValid(p, q)) {
				ar[p].pb(q);
				ar[q].pb(p);
			}
		}
	}
}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	vis[a] = true;
	dis[a] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : ar[curr]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = true;
				dis[child] = dis[curr] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, a, b;
	cin >> t;
	buildGraph();
	while (t--) {
		cin >> a >> b;
		for (int i = 1000; i <= 9999; i++)
			dis[i] = -1, vis[i] = 0;
		bfs(a);
		if (dis[b] == -1)
			cout << "Impossible\n";
		else
			cout << dis[b] << "\n";
	}
	return 0;
}