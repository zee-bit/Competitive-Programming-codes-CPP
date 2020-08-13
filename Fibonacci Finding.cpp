#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

void mul(ll a[][2], ll b[][2]) {
  ll res[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res[i][j] = 0;
      for (int k = 0; k < 2; k++)
        res[i][j] = ((res[i][j] % mod) + ((a[i][k] *                                b[k][j]) % mod)) % mod;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = res[i][j];
    }
  }
}

void calcTerm(int a, int b, int n) {
  ll magic[2][2] = {{0, 1}, {1, 1}};
  ll I[2][2] = {{1, 0}, {0, 1}};
  ll base[1][2] = {a, b};
  while (n) {
    if (n % 2) mul(I, magic);
    mul(magic, magic);
    n /= 2;
  }
  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      magic[i][j] = I[i][j];
    }
  }
  ll ans;
  mul(base, magic);
  ans = base[0][0];
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b, n;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n;
    ll ans = 0;
    if (n == 1) cout << b << '\n';
    else {
      calcTerm(a, b, n);
    }
  }
  return 0;
}