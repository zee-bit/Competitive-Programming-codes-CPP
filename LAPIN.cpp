#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool check_lap(string a, string b) {
	vector<int> ch(26,0);
	for(int i=0; i<a.length(); i++) 
		ch[a[i]-97]++;
	for(int i=0; i<b.length(); i++) 
		ch[b[i]-97]--;
	for(int i=0; i<26; i++) {
		if(ch[i]!=0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		string s, fh="", lh="";
		cin>>s;
		int mid=s.length()/2;
		fh=s.substr(0,mid);
		s.length()%2==0 ? lh=s.substr(mid):lh=s.substr(mid+1);
		// cout<<fh<<" "<<lh;
		if(fh==lh || check_lap(fh, lh))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}