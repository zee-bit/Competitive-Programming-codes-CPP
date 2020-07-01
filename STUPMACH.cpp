#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin>>n;
		int s[100],ans=0,min;
		for(int i=0;i<n;i++)
			cin>>s[i];
		ans=s[0];
		min=s[0];
		for(int i=1;i<n;i++)
		{
			if(s[i]<min)
				min=s[i];
			if(s[i]<=s[i-1] && s[i]<=min)
			{
				ans+=s[i];
			}
			else if((s[i]>s[i-1]) || (s[i]<=s[i-1] && s[i]>min))
			{
				ans+=min;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
