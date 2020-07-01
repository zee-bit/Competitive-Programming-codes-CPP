#include <iostream>
#include <math.h>
using namespace std;

long factors(long n)
{
	long min=100000000;
	for(long i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			long l=n/i;
			if((abs(l-i)<min)&&(abs(l-i)>=0))
				min=abs(l-i);
		}
	}
	return min;
}
int main()
{
	long t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<factors(n)<<"\n";
	}
	return 0;
}