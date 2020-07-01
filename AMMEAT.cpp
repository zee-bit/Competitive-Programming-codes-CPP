#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m, i;
	cin>>t;
	while(t--)
	{
		cin>>n >>m;
		long p[100];
		for(i=0;i<n;i++)
		{
			cin>>p[i];
		}
		sort(p,p+n,greater<long>());
		long totalMeatBall=0;
		for(i=0;i<n;i++)
		{
			totalMeatBall+=p[i];
			if(totalMeatBall >= m)
			{
				cout<<i+1<<"\n";
				break;
			}
			else if(i==n-1)
				cout<<"-1\n";
		}
	}
	return 0;
}