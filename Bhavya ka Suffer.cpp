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
#define umll unordered_map<ll, ll>
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
#define maxN 3e5+2;
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

void solve() {
	ll n, k;
	cin >> n >> k;
	vll a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	multiset<ll> ms;
	mll mp;
	rep(i, 0, k) {
		ms.I(a[i]);
		mp[a[i]]++;
	}
	auto beg = ms.begin(), end = ms.end();
	end--;
	ll diff = *end - *beg;
	rep(i, k, n) {
		ms.I(a[i]);
		mp[a[i]]++;
		if(mp[a[i - k]] == 1)
			ms.erase(a[i - k]);
		mp[a[i - k]]--;
		beg = ms.begin(), end = ms.end();
		end--;
		diff = min(diff, (*end - *beg));
	}
	cout << diff;
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
  		freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}