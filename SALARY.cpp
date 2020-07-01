#include <iostream>
using namespace std;

int main()
{
	long t,n,i,x;
	cin>>t;
	while(t--)
	{
		long min=10000,s=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			s+=x;
			if(x<min)
				min=x;
		}
		cout<<(s-(n*min))<<"\n";
	}
	return 0;
}