#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long goal[n], ans, maxm=0, minm=1000000007;
		for(long long i=0;i<n;i++)
		{
			cin>>goal[i];
		}
		for(long long i=0;i<n;i++)
		{
			if(goal[i]<minm)
				minm=goal[i];
			long long diff=goal[i] - minm;
			if(diff>maxm)
				maxm=diff;
		}
		if(maxm<=0)
			cout<<"UNFIT\n";
		else 
			cout<<maxm<<"\n";
	}
	return 0;
}