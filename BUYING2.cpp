#include <iostream>
using namespace std;

int main()
{
	int t,n,x,i,k,test=0;;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		int a[n];
		int s=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		k=s/x;
		for(i=0;i<n;i++)
		{
			if((s-a[i])>=(k*x))
			{
				test=-1;
				break;
			}
		}
		if(test==-1)
			cout<<test<<"\n";
		else
			cout<<k<<"\n";
		test=0;
	}
	return 0;
}