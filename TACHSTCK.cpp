#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long n,d,i,c=0;
	cin>>n>>d;
	long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=n-1;i>0;i--)
	{
		if((a[i]-a[i-1])<=d)
		{
			c++;
			i--;
		}
	}
	cout<<c;
	return 0;
}