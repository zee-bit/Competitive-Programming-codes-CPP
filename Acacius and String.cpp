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
// Important Edge Case ->
// 1
// 13
// abacab?bacaba

string comp = "abacaba";

int countSS(string &s) {
	int len = s.size(), cnt = 0;
	rep(i, 0, len) {
		if(s.substr(i, comp.size()) == comp)
			cnt++;
	}
	return cnt;
}

void solve() {
	int n, cnt, len;
	string s;
	cin >> n >> s;
	len = s.length();
	cnt = countSS(s);
	//cout << cnt << "\n";
	if(cnt > 1) {
		cout << "NO\n";
	}
	else if(cnt == 1) {
		cout << "YES\n";
		rep(i, 0, len) {
			if(s[i] == '?')
				s[i] = 'z';
		}
		cout << s << "\n";
	}
	else {	
		for(int i = 0; i + comp.size() <= n; i++) {
			string ss = s;
			bool ok = true;
			for(int j = 0; j < comp.size(); j++) {
				if(ss[i + j] != '?' && ss[i + j] != comp[j]) {
					ok = false;
					break;
				}
				ss[i + j] = comp[j];
			}
			if(ok && countSS(ss) == 1) {
				rep(j, 0, n) {
					if(ss[j] == '?')
						ss[j] = 'z';
				}
				cout << "YES\n";
				cout << ss << "\n";
				return;
			}
		}
		cout << "NO\n";
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