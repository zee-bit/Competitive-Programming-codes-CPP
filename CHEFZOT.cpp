#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	long n,i,pos=0,max=0;
	cin>>n;
	long a[100];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			if((i-pos)>=max)
			{
				max=i-pos;
				pos=i+1;
			}
			if(i-pos==0)
				pos=i+1;
		}
		if(i==n-1)
		{
			if(n-pos>max)
			{
				max=n-pos;
			}
		}
	}
	cout<<max;
	return 0;
}