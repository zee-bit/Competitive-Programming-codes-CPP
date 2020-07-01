#include <iostream>
#include <set>
using namespace std;

void solve() {
	int n, x, z, ans = 0;
	multiset<int, greater<int> > a;
	cin >> n >> z;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.insert(x);
	}
	multiset<int, greater<int> > :: iterator it = a.begin();
	
	bool esc = false;
	while(z > 0) {
		int power = *it;
		if(power == 0) {
			esc = true;
			break;
		}
		z -= power;
		a.insert(power / 2);
		a.erase(it);
		it = a.begin();
		ans++;
	}
	
	if(!esc)
		cout << ans << "\n";
	else
		cout << "Evacuate\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
