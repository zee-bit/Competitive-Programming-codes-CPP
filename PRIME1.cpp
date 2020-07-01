#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
	if(n==1)
		return false;
	int root=sqrt(n);
	for(int i=2;i<=root;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	long n, m ,t, i;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(i=m;i<=n;i++)
		{
			if(isPrime(i)==true)
				cout<<i<<"\n";
		}
		cout<<"\n";
	} 
	return 0;
}