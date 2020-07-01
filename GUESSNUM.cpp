#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,a,m;
	cin>>t;
	while(t--)
	{
		cin>>a>>m;
		long long n=m/a,k=0;
		long long ar[n];
		if(m%a==0)
		{
			cout<<"0\n\n";
			continue;
		}
		for(long long i=n;i>=1;i--)
		{
			for(long long j=n;j>=1;j--)
			{
				if(i%j==0)
				{
					if(((a*i)+j) == m)
					{
						ar[k]=i;
						k++;
						break;
					}
				}
			}
			if(i*a+i < m)
				break;
		}
		sort(ar,ar+k);
		cout<<k<<"\n";
		for(long long i=0;i<k;i++)
			cout<<ar[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
