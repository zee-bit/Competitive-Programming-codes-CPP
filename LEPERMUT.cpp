#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1];
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int ni=0,nli=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]>a[j])
					ni++;
			}
		}
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
				 nli++;
		}
		if(nli==ni)
		{
			cout<<"YES\n";
		}
		else
			cout<<"NO\n";
	}
	return 0;
}