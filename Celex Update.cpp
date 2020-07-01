//| 1 | 2 | 4 | 7 | 11 | 16
//|--------------------------
//| 3 | 5 | 8 | 12| 17 | 23
//|--------------------------
//| 6 | 9 | 13| 18| 24 | 32
//|--------------------------
//| 10| 14| 19| 25| 33 | 41
//|--------------------------
//| 15| 20| 27| 34| 42 | 51
//|--------------------------
//| 21| 28| 35| 43| 52 | 62
//|--------------------------
//|   |   |   |   |    |

//-> Minimum sum Path from (x1, y1) to (x2, y2)
//will be RRRR....DDDDD....(R = Right, D = Down)
//-> Maximum sum Path from (x1, y1) to (x2, y2)
//will be DDDD....RRRR....
//-> Moving from minimium sum to maximum sum path
//will increase the sum by 1 everytime.
//-> Thus ((x2 - x1) * (y2 - y1)) + 1 will give
//the number of different sum paths from start
//to end.

//Codeforces Rd.#645(div2)
//Author of THIS code - zean_7

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << ((x2 - x1) * (y2 - y1)) + 1 << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

