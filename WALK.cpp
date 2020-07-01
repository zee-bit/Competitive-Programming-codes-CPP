#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t,n,i,max;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long w[n];
		cin>>w[0];
		max=w[0];
		for(i=1;i<n;i++)
		{
			cin>>w[i];
			if(w[i]+i>max)
			{
				max=w[i]+i;
			}
		}
		cout<<max<<"\n";
	}
	return 0;
}