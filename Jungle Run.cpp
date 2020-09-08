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
int n, m;
char ar[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];

bool isValid(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n)
		return false;
	if(vis[x][y] || ar[x][y] == 'T')
		return false;
	return true;
}

void bfs(int srcX, int srcY, int d) {
	queue<pair<int, int> > q;
	q.push({srcX, srcY});
	vis[srcX][srcY] = true;
	dis[srcX][srcY] = d;
	while(!q.empty()) {
		int currX = q.front().ff;
		int currY = q.front().ss;
		q.pop();
		for(int i = 0; i < 4; i++) {
			if(isValid(currX + dx4[i], currY + dy4[i])) {
				int newX = currX + dx4[i];
				int newY = currY + dy4[i];
				q.push({newX, newY});
				vis[newX][newY] = true;
				dis[newX][newY] = dis[currX][currY] + 1;
			}
		}
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
	while(t--) {
		cin >> n;
		pair<int, int> start, end;
		rep(i, 1, n + 1) {
			rep(j, 1, n + 1) {
				cin >> ar[i][j];
				if(ar[i][j] == 'S')
					start = {i, j};
				if(ar[i][j] == 'E')
					end = {i, j};
			}
		}
		bfs(start.first, start.second, 0);
		cout << dis[end.first][end.second] << "\n";
	}
	return 0;
}