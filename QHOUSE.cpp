#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, lo = 0, hi = 1000, mid, bord;
	string q;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		cout << "? " << mid << " " << 0 << endl;
		cin >> q;
		if(q == "YES") {
			bord = mid;
			lo = mid + 1;
		}
		else 
			hi = mid - 1;
	}
	ans += 4 * bord * bord;
	
	int newBord1 = 2 * bord, newBord2 = bord;
	lo = newBord1, hi = 1000;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		cout << "? " << 0 << " " << mid << endl;
		cin >> q;
		if(q == "YES") {
			newBord1 = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	
	lo = newBord2, hi = 1000;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		cout << "? " << mid << " " << 2 * bord << endl;
		cin >> q;
		if(q == "YES") {
			newBord2 = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	newBord1 -= 2 * bord;
	
	ans += newBord1 * newBord2;
	
	cout << "! " << ans << endl;
	return 0;
}
