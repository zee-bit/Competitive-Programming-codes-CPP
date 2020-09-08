#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef long double ld;
struct custom_hash;
#define ff first
#define I insert
#define ss second
#define maxN 300002
#define inf INT_MAX
#define ninf INT_MIN
#define pb push_back
#define popb pop_back
#define pf push_front
#define pi 3.14159265
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define mod 1000000007
#define vi vector<int> 
#define mll map<ll, ll>
#define vll vector <ll>
const int dx4[]={-1,0,1,0};
const int dy4[]={0,1,0,-1};
#define vvi vector<vector<int> >
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const int dx8[]={-1,-1,-1,0,1,1,1,0,-1};
const int dy8[]={-1,0,1,1,1,0,-1,-1,-1};
#define ust unordered_set<ll, custom_hash>
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define umll unordered_map<ll, ll, custom_hash>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
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
const int l = ceil(log2(1001));
int LCA[1001][l + 1], n;
vi ar[1001], level(1001);

void dfs(int node, int par, int lvl = 0) {
	LCA[node][0] = par;
	level[node] = lvl;
	for(int child : ar[node]) {
		if(child != par)
			dfs(child, node, lvl + 1);
	}
}

void preCompute() {
	dfs(1, -1);
	rep(j, 1, l + 1) {
		rep(i, 1, n + 1) {
			if(LCA[i][j - 1] != -1) {
				int par = LCA[i][j - 1];
				LCA[i][j] = LCA[par][j - 1];
			}
		}
	}
}

int lca(int a, int b) {
	if(level[b] < level[a])	swap(a, b);
	int d = level[b] - level[a];
	while(d > 0) {
		int i = log2(d);
		b = LCA[b][i];
		d -= (1 << i);
	}
	if(a == b)
		return a;

	for(int i = l; i >= 0; i--) {
		if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
			a = LCA[a][i], b = LCA[b][i];
	}
	return LCA[a][0];
}

void solve() {
	int q;
	cin >> n;
	rep(i, 0, 1001) {
		rep(j, 0, l) {
			LCA[i][j] = -1;
		}
		ar[i].clear();
		level[i] = 0;
	}
	int a, b, x;
	rep(i, 1, n + 1) {
		cin >> x;
		rep(j, 0, x) {
			cin >> a;
			ar[i].pb(a);
		}
	}
	preCompute();
	cin >> q;
	rep(i, 0, q) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
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
	rep(i, 1, t + 1) {
		cout << "Case " << i << ":\n";
		solve();
	}
	return 0;
}