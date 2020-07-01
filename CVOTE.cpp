#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
	int m, n, ma = 0;
	string x, y;
	cin >> n >> m;
	map<string, string> mapping;
	map<string, int> country;
	map<string, int> name;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		mapping.insert(pair<string, string>(x, y));
		if(name.find(x) == name.end())
			name.insert(pair<string, int>(x, 0));
		if(country.find(y) == country.end())
			country.insert(pair<string, int>(y, 0));
	}
	for(int i = 0; i < m; i++) {
		cin >> x;
		name[x] += 1;
		country[mapping[x]] += 1;
	}
	map<string, int> :: iterator it;
	
	string ansCont, ansChef;
	
	it = country.begin();
	ma = it->second;
	ansCont = it->first;
	it++;
	for( ; it != country.end(); it++) {
		if(it->second > ma) {
			ansCont = it->first;
			ma = it->second;
		}
		else if(it->second == ma && it->first < ansCont) {
			ansCont = it->first;
			ma = it->second;
		}
	}
	
	it = name.begin();
	ma = it->second;
	ansChef = it->first;
	it++;
	for( ; it != name.end(); it++) {
		if(it->second > ma) {
			ansChef = it->first;
			ma = it->second;
		}
		else if(it->second == ma && it->first < ansChef) {
			ansChef = it->first;
			ma = it->second;
		}
	}
	cout << ansCont << "\n" << ansChef;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
