#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sc[12]={0};
		int p,s,ans=0;
		for(i=0;i<n;i++)
		{
			cin>>p>>s;
			if(p<=8)
			{
				sc[p]=max(sc[p],s);
			}
		}
		for(i=1;i<=8;i++)
			ans+=sc[i];
		cout<<ans<<"\n";
	}
	return 0;
}