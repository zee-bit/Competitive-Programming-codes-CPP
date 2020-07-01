#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), stk;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++) {
		if(stk.empty())
			stk.push_back(a[i]);
		else if(upper_bound(stk.begin(), stk.end(), a[i]) == stk.end())
			stk.push_back(a[i]);
		else
			*upper_bound(stk.begin(), stk.end(), a[i]) = a[i];
	}
	cout << stk.size() << " ";
	for(int i = 0; i < stk.size(); i++)
		cout << stk[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	while(t--)
		solve();
	return 0;
}
