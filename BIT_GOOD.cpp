#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define mod 1000000007
using namespace std;

int main() {
	int n, ans=0, c=0, fix=0;
	cin>>n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a.begin(), a.end());
	for(int i=n-1;i>=0;i--)
{
    if(c>=3)
    {
        if(a[i]>0 && a[i]<fix)
        {
            ans+=a[i];
            ans%=mod;
        }
        
    }
    else if(mp[0-a[i]]==0)
        {
            c++;
            if(c==3)
             fix=a[i];
        }
}
	cout<<ans;
	return 0;
}