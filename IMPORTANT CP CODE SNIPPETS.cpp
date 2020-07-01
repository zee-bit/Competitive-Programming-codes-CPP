#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
//----------------------------------------------
//Fast Exponentiation [(base^exp) % mod]
//----------------------------------------------
ll fast_exp(ll base, ll exp) {
	ll result = 1;
	while (exp) {
		if (exp % 2) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}


//-----------------------------------------------
// Modular multiplication [(a * b) % mod]
// Constraint : [0 <= a, b <= 10^9]
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
//Method 2: Using Tuples from STL
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
// Sometimes using inbuilt ceil function may lead
// to WA, because it outputs float values. Try using
// this instead of ceil(A / B)
//-----------------------------------------------
ceil(a / b) = (a + b - 1) / b;

//-----------------------------------------------
// For printing large float values without their
// scientific notation (e.g. 1.67543e002)
//-----------------------------------------------
cout << fixed << set_precision(9) << your_output;

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
//Sieve of Eratosthenes   [O(n)]
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
//Lower bound implementation using Binary Search
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






