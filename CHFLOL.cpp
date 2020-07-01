#include <iostream>
using namespace std;

int main()
{
	long s=0,t,n,i,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x>0)
				s+=x;
		}
		cout<<s<<"\n";
	}
	return 0;
}