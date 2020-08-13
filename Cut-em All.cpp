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

#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> ar[100001];
bool vis[100001];
int ans;

int dfs(int node, int par) {
    vis[node] = true;
    int s = 0;
    for (int child : ar[node]) {
        if (!vis[child])
            s += dfs(child, node);
    }
    ans += (s % 2);
    return s + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, u, v;
    cin >> n;
    if (n % 2)
        return puts("-1\n");
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    dfs(1, 0);
    cout << ans - 1 << "\n";
    return 0;
}