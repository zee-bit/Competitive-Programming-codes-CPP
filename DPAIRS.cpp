#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
	int m, n;
	cin >> n >> m;
	vector<int> a(n), b(m);
	map<int, int> posA, posB;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		posA.insert(pair<int,int>(a[i], i));
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		posB.insert(pair<int, int>(b[i], i));
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for(int i = 0; i < m; i++) 
		cout << posA[a[0]] << " " << posB[b[i]] <<"\n";
		
	for(int i = 1; i < n; i++) 
		cout << posA[a[i]] << " " << posB[b[m - 1]] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
