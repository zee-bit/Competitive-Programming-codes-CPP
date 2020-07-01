#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> d(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		d[i + n] = d[i];
	}
	vector<ll> prefixSum(2 * n, 0), daySum(2 * n, 0);
	prefixSum[0] = d[0];
	daySum[0] = d[0] * (d[0] + 1) / 2;
	for (int i = 1; i < 2 * n; i++) {
		prefixSum[i] = prefixSum[i - 1] + d[i];
		daySum[i] = daySum[i - 1] + (d[i] * (d[i] + 1)) / 2;
	}
	ll ans = 0, sum = 0;
	for (int i = 2 * n - 1; i >= n; i--) {
		int lo = 0, hi = i, mid, a;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (prefixSum[i] - prefixSum[mid] < x) {
				a = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		ll diff = prefixSum[i] - prefixSum[a - 1] - x;
		diff = diff * (diff + 1) / 2;
		sum = daySum[i] - daySum[a - 1] - diff;
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}