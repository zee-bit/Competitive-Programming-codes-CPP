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
const int mx8[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int my8[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool vis[8][8];
int dis[8][8];

bool isPoss(int x, int y) {
	if(x >= 8 || y >= 8 || x < 0 || y < 0)	
		return false;
	if(vis[x][y])	
		return false;
	return true;
}

int bfs(int srcx, int srcy, int desx, int desy) {
	vis[srcx][srcy] = true;
	dis[srcx][srcy] = 0;
	if(srcx == desx && srcy == desy)
		return 0;
	queue<pair<int, int> > q;
	q.push({srcx, srcy});
	while(!q.empty()) {
		pair<int,int> c = q.front();
		q.pop();
		int cx = c.ff, cy = c.ss;
		rep(i, 0, 8) {
			int newX = cx + mx8[i], newY = cy + my8[i];
			if(isPoss(newX, newY)) {
				if(newX == desx && newY == desy)
					return dis[cx][cy] + 1;
				dis[newX][newY] = dis[cx][cy] + 1;
				q.push({newX, newY});
				vis[newX][newY] = true;
			}
		}
	}
}

void solve() {
	string a, b;
	cin >> a >> b;
	int sx = a[0] - 'a', sy = a[1] - '1';
	int dx = b[0] - 'a', dy = b[1] - '1';
	//cout << sx << sy << dx << dy;
	rep(i, 0, 8) {
		rep(j, 0, 8) {
			vis[i][j] = false;
		}
	}
	cout << bfs(sx, sy, dx, dy) << "\n";
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