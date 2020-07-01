#include <iostream>
using namespace std;

int main()
{
	long long t,n,k,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long a[n],b[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		long long max=0,pick,profit;
		for(i=0;i<n;i++)
		{
			pick=k/a[i];
			profit=pick*b[i];
			if(profit>max)
				max=profit;
		}
		cout<<max<<"\n";
	}
	return 0;
}