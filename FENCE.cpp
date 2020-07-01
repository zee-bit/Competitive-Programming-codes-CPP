#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, k, x, y;
	cin >> n >> m >> k;
	set<pair<int, int> > plant;
	for(int i = 0; i < k; i++) {
		cin >> x >> y;
		plant.insert(pair<int, int>(x, y));
	}
	ll ans = 0;
	set<pair<int, int> > :: iterator it;
	for(it = plant.begin(); it != plant.end(); it++) {
		int ctr = 0;
		pair<int, int> left, right, up, down;
		
		left.first = (*it).first;
		left.second = (*it).second - 1;
		
		right.first = (*it).first;
		right.second = (*it).second + 1;
		
		up.first = (*it).first - 1;
		up.second = (*it).second;
		
		down.first = (*it).first + 1;
		down.second = (*it).second;
		
		if(plant.find(left) != plant.end())
			ctr++;
		if(plant.find(right) != plant.end())
			ctr++;
		if(plant.find(up) != plant.end())
			ctr++;
		if(plant.find(down) != plant.end())
			ctr++;
		ans += 4 - ctr;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; 
	cin>>t;
	while(t--) 
		solve();
	return 0;
}
