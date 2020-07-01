#include <bits/stdc++.h>
using namespace std;

set<int> state;
int pos(int a) {
	auto it = state.lower_bound(a);
	if(state.count(a))
		return *it;
	else {
		it--;
		return *it;
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1 , -1);
	
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
		
	state.insert(1);
	for(int i = 2; i <= n; i++) {
		if(a[i] % a[i - 1] != 0)
			state.insert(i);
	}
	int op, idx, val;
	for(int i = 0; i < q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> idx >> val;
			state.insert(idx);
			state.insert(idx + 1);
			a[idx] = val;
			if(idx != n){
				if(a[idx + 1] % a[idx] == 0 && pos(idx) != pos(idx + 1)){
					state.erase(state.find(pos(idx+1)));
				}
				else if(a[idx+1] % a[idx] !=0 && pos(idx) == pos(idx+1)){
					state.insert(idx+1);
				}
			}
			if(idx != 1){
				if(a[idx] % a[idx-1] == 0 && pos(idx) != pos(idx-1)){
					state.erase(state.find(pos(idx)));
				}
				else if(a[idx] % a[idx-1]!=0 && pos(idx) == pos(idx-1)){
					state.insert(idx);
				}
			}
		}
		else {
			cin >> idx;
			set<int> :: iterator it;
			it = state.upper_bound(idx);
			if(it != state.begin())
				--it;
			cout << *it << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	return 0;
}
