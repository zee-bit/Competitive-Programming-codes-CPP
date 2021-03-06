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
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0, h = 1000000, mid, ans = 1;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(((mid * (mid + 1)) / 2LL) <= k) {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    //cout << ans;
    int p = ans * (ans + 1) / 2;
    int pos = k - p == 0 ? ans - 1 : k - p -1;
    cout << a[pos] << "\n";

    // Or more Easy solution, without using Binary Search

    ll n,k; cin>>n>>k;
    vll a(n + 1);
    rep(i, 1,n+1) cin>>a[i];
    rep(i, 1,n+1)
    {
        if(k-i>0)
        {
            k-=i;
            continue;
        }
        cout<<a[k];
        return;
    }
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