#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calculate(ll n, ll *dp) {
	if(dp[n])
		return dp[n];
	if(n<2)
		return n;
	dp[n]=max(n, calculate(n/2, dp)+calculate(n/3, dp)+calculate(n/4, dp));
	return dp[n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while(cin>>n)
	{
		ll *dp=new ll[n+1];
		// for(ll i=0;i<=n;i++)
		// {
		// 	dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
		// }
		cout<<calculate(n,dp)<<"\n";
	}
	return 0;
}
