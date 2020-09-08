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
#define vvi vector<vector<int> >
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
vi a(1005);
int cache[1005][1005], dp[1005][1005], k;

int calcAns(int i, int j) {
	if(i == j)	return 0;
	if(dp[i][j] != 1000000)	return dp[i][j];
	int ans = 100000;
	rep(l, i, j) {
		dp[i][l] = cache[i][l];
		int val = calcAns(l + 1, j) + cache[i][l];
		ans = min(ans, val);
	}
	dp[i][j] = ans;
	return ans;
}

void solve() {
	int n;
	cin >> n >> k;
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, 1005) {
		rep(j, 0, 1005) {
			cache[i][j] = -1;
			dp[i][j] = 1000000;
		}
	}
	umll mp;
	rep(i, 0, n) {
		mp.clear();
		int total = k;
		rep(j, i, n) {
			mp[a[j]]++;
			if(mp[a[j]] > 1) {
				if(mp[a[j]] == 2)
					total += 2;
				else
					total += 1;
			}
			cache[i][j] = total;
		}
	}
	cout << calcAns(0, n) << "\n";
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