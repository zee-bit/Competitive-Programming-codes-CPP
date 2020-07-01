#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,n,i;
	cin>>t;
	while(t--)
	{
		long long s=0;
		cin>>n;
		long long a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a, a+n, greater<long long>());
		for(i=0;i<n;i+=2)
		{
			s=s+a[i];
		}
		cout<<s<<"\n";
	}
	return 0;
}