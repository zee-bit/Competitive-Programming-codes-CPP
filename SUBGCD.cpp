#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t,n,i,g=0;
	bool flag=false;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a[100];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
				flag=true;
		}
		if(flag==true)
			cout<<n<<"\n";
		else
		{
			g=__gcd(a[0],a[1]);
			if(g==1)
				cout<<n<<"\n";
			else
			{
				for(i=2;i<n;i++)
				{
					g=__gcd(g,a[i]);
				}
				if(g==1)
					cout<<n<<"\n";
				else
					cout<<-1<<"\n";
			}
		}
		flag=false;
		g=0;
	}
	return 0;
}