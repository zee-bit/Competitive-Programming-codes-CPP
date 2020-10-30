/************************************************
				Author -> zean_7
************************************************/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define maxN 1000001
typedef long long ll;

//----------------------------------------------
// Bit Manipulation
//----------------------------------------------
void bitManipulate(int n) {
	// 1. Extracting i'th bit of number
	int ithBit = (n & (1 << i));

	// 2. Setting i'th bit of a number 
	(n | (1 << i));

	// 3. Resetting i'th bit of a number
	(n & (~(1 << i)))

	// 4. Creating mask of first set bit of a number
	(n & (~(n - 1)))
}

//----------------------------------------------
// Counting set bits in a number
//----------------------------------------------
int countSetBits(int n) {
	int ans = 0;
	while (n) {
		if (n & 1)
			ans++;
		n = n >> 1;
	}
	return ans;
}
// A bit faster approach would be this!!
// This method would run equal to the number
// of set bits in 'n' times, rather than logN
int countSetBits(int n) {
	int ans = 0;
	while (n) {
		ans++;
		n = n & (n - 1);
	}
	return ans;
}

//-----------------------------------------------
// Count Unique Bitwise OR of all subarrays
//-----------------------------------------------
int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> st;
    int n = A.size(), chk = 0, curr;
    for(int i = n - 1; i >= 0; i--) {
        curr = A[i];
        st.insert(curr);
        chk = 0;
        for(int j = i + 1; j < n && chk != curr; j++) {
            curr |= A[j];
            chk |= A[j];
            st.insert(curr);
        }
    }
    return st.size();
}

//-----------------------------------------------
// Sometimes using inbuilt ceil function may lead
// to WA, because it outputs float values. Try using
// this instead of ceil(A / B)
//-----------------------------------------------
ceil(a / b) = (a + b - 1) / b;


// VERY IMPORTANT
//------------------------------------------------
// Pragmas in GCC can optimize your code almost x8
// times. So, even an O(n^2) naive solution MAY
// get accepted under 2sec. 
//------------------------------------------------
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

//----------------------------------------------
//Fast Exponentiation [(base^exp) % mod]
//----------------------------------------------
ll fast_exp(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp % 2) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

//-----------------------------------------------
// Modular multiplication [(a * b) % mod]
// Constraint : [0 <= a, b <= 10^18]
//-----------------------------------------------
// This code will have a complexity of O(log b), but
// we can use __int128 in C++ to avoid any potential
// overflows and work in O(1).
ll mod_mul(ll a, ll b, ll mod) {
	ll x = 0, y = a;
	while (b > 0) {
		if (b & 1)
			x = (x + y) % mod;
		y = (y + y) % mod;
		b >>= 1;
	}
	return x;
}

// IMPORTANT....Gave many WA. XD
//-----------------------------------------------
// When subtracting two mod'ed values, if the answer
// becomes negative, add mod to the answer.
// e.g. if [(2 ^ n) % mod - (n!) % mod] < 0, then
// add mod to the result.
//-----------------------------------------------

//-----------------------------------------------
// Moore's Voting Algorithm (Majority element)
// Time -> O(n) || Space -> O(1)
//-----------------------------------------------
int findCandidate(vector<int> a) {
	int len = a.size(), majIndex = 0, cnt = 1;
	for(int i = 1; i < len; i++) {
		if(a[i] == a[majIndex])
			cnt++;
		else
			cnt--;
		if(cnt == 0) {
			majIndex = i;
			cnt = 1;
		}
	} 
	cnt = 0;
	for(int i = 0; i < len; i++) {
		if(a[i] == a[majIndex])
			cnt++;
	}
	if(2 * cnt > len)
		return a[majIndex];
	else
		return -1;
}

//-----------------------------------------------
//Euclid's GCD Algorithm (Basic)
//-----------------------------------------------
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//-----------------------------------------------
//Euclid's GCD Algorithm (Extended) [ax + by = gcd(a,b)]
//-----------------------------------------------
//METHOD 1: Using Pointers
int gcdExtended(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

//Method 2: Recursive
int gcdExtended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//Method 3: Using Tuples from STL
tuple<int, int, int> extended_gcd(int a, int b) {
	if (a == 0)
		return make_tuple(b, 0, 1);
	int gcd, x, y;
	// unpack tuple returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b / a) * x), x);
}

//-----------------------------------------------
// GOLDBACH CONJECTURE: Every even integer greater
//     than 2 can be written as the sum of two
//     prime numbers.
//-----------------------------------------------

//-----------------------------------------------
// 2-D vector declaration of size N x N
//-----------------------------------------------
vector<vector<int> > a(N, vector<int>(N, 0));

//-----------------------------------------------
// For printing large float values without their
// scientific notation (i.e. not like 1.67543e002)
//-----------------------------------------------
cout << fixed << setprecision(9) << your_output;

//-----------------------------------------------
//Sieve of Eratosthenes  [O(n * log (log n))]
//-----------------------------------------------
void sieve(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}

//-----------------------------------------------
//Sieve of Eratosthenes   (Queried)
//-----------------------------------------------
void fast_sieve(int n) {
	vector<int> pr, lp(n + 1);
	//lp[i] = 0, means i is prime, and we havent
	//found any smaller factors of it.

	//lp[i] != 0, means i is composite and its
	//minimum prime factor is lp[i]

	for (int i = 2; i <= n; i++) {
		if (!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

//-----------------------------------------------
// Prime Factorization [O(sqrt(N))]
//-----------------------------------------------
void primeFactorization(int n) {
	for (int i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		cout << i << " ^ " << cnt << "\n";
	}
	if (n > 1)
		cout << n << " ^ " << 1 << "\n";
}

//-----------------------------------------------
// Prime Factorization using Sieves in case of
// queries O(log(N))  // Pre-computation
//-----------------------------------------------
int leastPrime[1000001];
void leastPrimeUsingSieve() {
	for (int i = 1; i <= 1000000; i++)
		leastPrime[i] = -1;
	for (int i = 2; i * i <= 1000000; i++) {
		if (leastPrime[i] == -1) {
			for (int j = i * i; j <= 1000000; j += i)
				if (leastPrime[i] == -1)
					leastPrime[j] = i;
		}
	}
}

//-----------------------------------------------
// Lower bound implementation using Binary Search
// Find smallest value >=X
//-----------------------------------------------
int lowerBound(vector<int> arr, int x) {
	sort(arr.begin(), arr.end());
	int ans = -1, lo = 0, hi = arr.size() - 1, mid;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (arr[mid] >= x) {
			ans = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return ans;
}


//-----------------------------------------------
// Finding sqrt of a number with precision using
// Binary Search
//-----------------------------------------------
int bschsqrt(int n, float precs) {
	float l = 0, r = n, mid;
	while (r - l > precs) {
		mid = l + (r - l) / 2;
		if (mid * mid < n)
			l = mid;
		else
			r = mid;
	}
	return l + (r - l) / 2;
}


//-----------------------------------------------
//Finding ALL the sum of subsets of an array.
//(Bit Masking) [O(N*(2^N))]
//-----------------------------------------------
void subsets(vector<int> arr, int n) {
	for (int mask = 0; mask < (1 << n); mask++) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				sum += arr[i];
			}
		}
	}
}


//-----------------------------------------------
//Finding the intersection of two arrays(Bitset method)
//-----------------------------------------------
const int n = 12; //Number of arrays for comparison
bitset<200> x[n];
int intersection(int i, int j) {
	return (x[i] & x[j]).count();
}


//-----------------------------------------------
//Counting number of unique values in an array
// n=10^7   a[i]<=10^9
//-----------------------------------------------
//This could also be done using unordered_set/maps, but
//it'd be more efficint & faster using bitsests
bitset<1000000001> visited;
int unique(int n) {
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		visited[x] = true;
	}
	return visited.count();
}


//-----------------------------------------------
//Check whether sum of any subset is equal to W.
// N<=10^3      W<=10^6
//-----------------------------------------------
bitset<1000001> can;
bool isSubsetSumEqual(int n, int w) {
	can[0] = true;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		can = can | (can << x); //can |= can<<x;
	}
	return can[w];
}


//----------------------------------------
//Finding nCr efficiently
//----------------------------------------
int nCr(int n, int r) {
	ll p = 1, k = 1; //p holds n*(n-1)*.. ; k holds r*(r-1)*...
	// C(n, r)==C(n, n-r)
	if (n - r < r)
		r = n - r;
	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			ll m = __gcd(p, k);
			//dividing by gcd will simplify
			//the product
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else
		p = 1;
	return p;
}

//------------------------------------------
// Longest Increasing Subsequence O(NlogN)
//------------------------------------------
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

//------------------------------------------
// Tower of Hanoi (Recursion)
//------------------------------------------
void TowerOfHanoi(string src, string des, string help, int n) {
	if (n == 0)
		return;

	// PHASE 1: Move n-1 disc from src to help
	// using des.
	TowerOfHanoi(src, help, des, n - 1);
	// Moving the main base disc
	cout << "Move disc " + n + " from " + src + " " + help + "\n";
	// PHASE 2: Move n-1 disc from help to des
	// using src.
	TowerOfHanoi(help, des, src, n - 1);
}

//------------------------------------------
// Kadane's Algorithm [Maximum subarray sum]
//------------------------------------------
int maxSubarraySum(vector<int> &a) {
	// currMax will store the maximum till a[i - 1]
	// globalMax will store the maximum till a[i]
	int currMax = a[0], globalMax = a[0], l = a.size();
	for (int i = 1; i < l; i++) {
		currMax = max(a[i], currMax + a[i]);
		globalMax = max(currMax, globalMax);
	}
	return globalMax;
}

//-------------------------------------------
// Depth-First Search (DFS)
//-------------------------------------------
bool visited[maxN];
void dfs(int v) {
	visited[v] = true;
	/* Do Some task */
	for (int i = 0; i < ar[v].size(); i++) {
		int child = ar[v][i];
		if (!visited[child])
			dfs(child);
	}
}

//---------------------------------------------
// Bipartite Graph Test
//---------------------------------------------
// Let the two colors be 0 -> black, 1-> white
bool visited[maxN], color[maxN];
bool dfs(int v, bool c) {
	visited[v] = true;
	color[v] = c;
	for (int child : ar[v]) {
		if (!visited[child]) {
			if (dfs(child, !c) == false)
				return false;
		}
		else {
			if (color[v] == color[child])
				return false;
		}
	}
	return true;
}

//----------------------------------------------
// Checking for cycle in graphs using dfs
//----------------------------------------------
bool visited[maxN];
bool dfs(int v, int parent) {
	visited[v] = true;
	for (int child : ar[v]) {
		if (!visited[child]) {
			if (dfs(child, v))
				return true;
		}
		else {
			if (child != parent)
				return true;
		}
	}
	return false;
}

//----------------------------------------------
// In / Out Time for vertices of a graph
// Eulers Tour
//----------------------------------------------
int inTime[maxN], outTime[maxN], timer = 1;
bool visited[maxN];

void dfs(int node) {
	visited[node] = true;
	inTime[node] = timer++;
	for (int child : ar[node]) {
		if (!visited[child])
			dfs(child);
	}
	outTime[node] = timer++;
}

//---------------------------------------------
// Subtree size Using DFS
//---------------------------------------------
bool vis[maxN];
int subSize[maxN];

int dfs(int node) {
	vis[node] = true;
	int curr_size = 1;
	for (int child : ar[node]) {
		if (!vis[child])
			curr_size += dfs(child);
	}
	subSize[node] = curr_size;
	return curr_size;
}

//----------------------------------------------
// Single Source Shortest Path (SSSP)
//----------------------------------------------
bool vis[maxN];
int dis[maxN];

// Using DFS (Only for TREES)
void dfs(int node, int d) {
	vis[node] = true;
	dis[node] = d;
	for (int child : ar[node]) {
		if (!vis[child])
			dfs(child, d + 1);
	}
}

// Using BFS
void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = true;
	dis[src] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int child : a[curr]) {
			if (!vis[child]) {
				q.push(child);
				dis[child] = dis[curr] + 1;
				vis[child] = true;
			}
		}
	}
}

//------------------------------------------------
// Finding bridge edges in a graph using DFS
//------------------------------------------------
bool vis[maxN];
vector<int> ar[maxN], inTime(maxN), low(maxN);
int timer = 0;

void dfs(int node, int par = -1) {
	vis[node] = true;
	inTime[node] = low[node] = timer++;

	for (int child : ar[node]) {
		if (child == par)
			continue;

		if (vis[child]) {
			// This node is a back-edge
			low[node] = min(low[node], inTime[child]);
		}
		else {
			// This edge is a forward edge
			dfs(child, node);

			if (low[child] > inTime[node])
				cout << node << "->" << child << " is a bridge.";

			low[node] = min(low[node], low[child]);
		}
	}
}

//------------------------------------------------
// Finding Articulation Points (Cut-vertices)
//------------------------------------------------
bool vis[maxN];
vector<int> ar[maxN], inTime(maxN), low(maxN), cut_verts;
int timer = 0;

void dfs(int node, int par = -1) {
	vis[node] = true;
	inTime[node] = low[node] = timer++;

	int children = 0;
	for (int child : ar[node]) {
		if (child == par)
			continue;

		if (vis[child]) {
			// This node is a back-edge
			low[node] = min(low[node], inTime[child]);
		}
		else {
			// This edge is a forward edge
			dfs(child, node);

			// Considering vertex 1 is the root
			if (low[child] >= inTime[node] && par != -1) {
				// This edge is a bridge
				cut_verts.pb(node);
			}
			children++;
			low[node] = min(low[node], low[child]);
		}
	}
	if (par == -1 && children > 1)
		cut_verts.pb(node);
}

//-------------------------------------------------
// Kahn's Algorithm for Topological Sorting
//-------------------------------------------------
vector<int> ar[maxN], topSort(maxN), inEdge(maxN);

void kahn(int src) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inEdge[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int curr = q.front();
		topSort.push_back(curr);
		q.pop();

		for (int child : ar[curr]) {
			inEdge[child]--;
			if (inEdge[child] == 0)
				q.push(child);
		}
	}
	cout << "Topological Sort ->";
	for (int node : topSort)
		cout << node << " ";
}

void makeTree() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ar[u].push_back(v);
		inEdge[v]++;
	}
	kahn(1);
}

//----------------------------------------------------
// Least Common Ancestor(LCA) using Binary Lifting 
// in case of queried input. 
// Preprocessing -> O(Nlog(N))
// Query OP -> O(log(n))
//----------------------------------------------------
// LCA[i][j] = (2^j)th Parent of Node i.
const int l = ceil(log2(maxN));
int LCA[maxN][l + 1], n;
vi ar[maxN], level(maxN);

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
// If it is required to find the distance between 
// two given nodes then,
// dist = level[a] + level[b] - 2 * level[LCA]
int getDist(int a, int b) {
	return level[a] + level[b] - 2 * level[lca(a, b)];
}


//----------------------------------------------------
// Dijkstra's Algorithm for Shortest Path from given 
// vertex. Using Priority queue
//----------------------------------------------------
// adj[i] = Pair of nodes connected with i having 
// weight w of the form {node, w};
vector<pair<int, int> > adj[maxN];

void dijkstra() {
	int n, m, a, b, w;
	rep(i, 0, n) adj[i].clear();
	cin >> n >> m;
	rep(i, 0, m) {
		cin >> a >> b >> w;
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}

	// Pair of {distance, node} 
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dis(n + 1, inf);
	pq.push({0, 1});
	dis[1] = 0;

	while(!pq.empty()) {
		int currNode = pq.top().ss;
		int currDis = pq.top().ff;
		pq.pop();
		for(auto child : adj[currNode]) {
			if(currDis + child.ss < dis[child.ff]) {
				dis[child.ff] = currDis + child.ss;
				pq.push({dis[child.ff], child.ff});
			}
		}
	}
	rep(i, 1, n + 1) {
		cout << dis[i] << " ";
	}
}


//----------------------------------------------------------
// Coin Change (Minimum coins needed to make given sum)
//----------------------------------------------------------
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i=1; i<=amount; i++) {
        for(int j:coins) {
            if(j<=i)
                dp[i] = min(dp[i], dp[i-j]);
        }
        dp[i]++;
    }
    return dp[amount]>amount?-1:dp[amount];
}

//-------------------------------------------------------
// Coin Change (Number of ways to make given sum)
//-------------------------------------------------------
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for(int coin : coins) {
		for(j = 1; j < amount + 1; j++) {
			if(coin <= j)
				dp[j] += dp[j - coin];
		}
	}
	cout << dp[amount] << "\n";
}