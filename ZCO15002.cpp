#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long ll;

int main()
{
	ll n, k,ans=0;
	cin>>n>>k;
	vector<ll> num(n);
	for(ll i=0;i<n;i++)
		cin>>num[i];
	sort(num.begin(),num.end());
	for(ll i=0;i<n;i++)
	{
		int temp=lower_bound(num.begin(),num.end(),num[i]+k) - num.begin();
		ans+=n-temp;
	}
	cout<<ans;
	return 0;
}