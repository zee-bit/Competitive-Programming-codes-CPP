#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t,n,i,ans=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a[1000];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,greater<long>());
		for(i=0;i<n;i++)
		{
			if(i%4<2)
				ans+=a[i];
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}