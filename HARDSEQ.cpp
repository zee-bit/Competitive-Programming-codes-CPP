#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,x,i,j;
	cin>>t;
	while(t--)
	{
		x=0;
		cin>>n;
		int a[n];
		a[0]=0;
		a[1]=0;
		for(i=2;i<n;i++)
		{
			bool flag=false;
			for(j=i-2;j>=0;j--)
			{
				if(a[j]==a[i-1])
				{
					a[i]=abs(i-1-j);
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				a[i]=0;
			}
		}
		for(i=0;i<n;i++)
		{		
			if(a[i]==a[n-1])
			{
				x++;
			}
		}
		cout<<x<<"\n";
	}
	return 0;
}