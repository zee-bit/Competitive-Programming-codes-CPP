#include <iostream>
#include <algorithm>
using namespace std;

int divisor(int n)
{
	int i, ans=0;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans++;
			if(i*i!=n)
				ans++;
		}
	}
	return ans;
}
int main()
{
	int t, a, b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(abs(a-b) == 0)
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<divisor(abs(a-b))<<"\n";
		}
	}
	return 0;
}