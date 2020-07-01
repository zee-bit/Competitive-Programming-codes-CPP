#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,t,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long a[100],count_2=0,count_0=0;;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==2)
				count_2++;
			else if(a[i]==0)
				count_0++;
		}
		count_0=(long long)((count_0)*(count_0 - 1))/2;
		count_2=(long long)((count_2)*(count_2 - 1))/2;
		long long ans=count_2+count_0;
		cout<<ans<<"\n";
	}
	return 0;
}