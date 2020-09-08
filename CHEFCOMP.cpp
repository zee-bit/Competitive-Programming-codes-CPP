#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define I insert
#define vi vector<int> 
#define vvi vector<vector<int> > 
#define mll map<ll, ll>
#define umll unordered_map<ll, ll, custom_hash>
#define usl unordered_set<ll, custom_hash>
#define vll vector <ll>
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define popb pop_back
#define mod 1000000007
#define pi 3.14159265
#define inf INT_MAX;
#define ninf INT_MIN;
#define maxN 300002
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, a, b) for(ll i = a; i < b; i++)
struct custom_hash { size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().count();x ^= FIXED_RANDOM;return x ^ (x >> 16);}};
ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;} 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
{mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}

//========================================XXXXXXXXXXXXXXXX=======================================
vll ar[maxN], p(maxN), a(maxN), b(maxN), ans(maxN);
ll d = 1;
usl st;

void dfs(ll node, ll root, ll par = 0) {
	b[node] -= min(a[root], b[node]);
	//cout << node << " " << b[node] << "\n";
	if(b[node] <= 0 && ans[node] == 0) 
		ans[node] = d;
	for(auto child : ar[node]) {
		if(child == par)
			continue;
		if(st.count(child))
			continue;
		dfs(child, root, node);
	}
	// b[node] -= min(a[root], b[node]);
	// if(b[node] <= 0) 
	// 	ans[node] = d;
}

void solve() {
	ll n, u, v;
	cin >> n;
	rep(i, 1 , n) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	rep(i, 1, n + 1) {
		cin >> p[i];
	}
	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	rep(i, 1, n + 1) {
		cin >> b[i];
	}
	rep(i, 1, n + 1) {
		dfs(p[i], p[i], 0);
		st.I(p[i]);
		d++;
	}
	rep(i, 1, n + 1) {
		if(ans[i] == 0)
			cout << "-1 ";
		else
			cout << ans[i] << " ";
	}
	cout << "\n";
	rep(i, 1, n + 1) {
		ar[i].clear();
		st.clear();
		d = 1;
		ans[i] = 0;
		p[i] = 0, a[i] = 0, b[i] = 0;
	}
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
  		freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}