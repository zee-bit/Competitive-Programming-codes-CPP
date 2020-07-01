#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else 
		return(gcd(b,a%b));
}
int main()
{
	int t,i,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n==1)
			cout<<a[0]<<"\n";
		else if(n==2)
			cout<<gcd(a[0],a[1])<<"\n";
		else
		{
			int g;
			g=gcd(a[0],a[1]);
			for(i=2;i<n;i++)
			{
				g=gcd(g,a[i]);
			}
			cout<<g<<"\n";
		}
	}
	return 0;
}