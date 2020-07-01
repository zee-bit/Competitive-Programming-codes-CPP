#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+1], max=0;
		a[0]=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		sort(a,a+n+1);
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[i-1] > max)
				max=a[i]-a[i-1];
		}
		if(max > a[1])
			max=a[1];
		cout<<max<<"\n";
	}
	return 0;
} 