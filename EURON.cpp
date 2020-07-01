#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	multiset<int> st;
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(st.empty()) 
			st.insert(a[i]);
		else {
			auto it = st.upper_bound(a[i]);
			if(it != st.end()) 
				ans += st.end() - it;
			st.insert(a[i]);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	return 0;
}
