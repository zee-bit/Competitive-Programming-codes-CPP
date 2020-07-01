#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int t, n, k, i, j, pos=-1;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		string s[n];
		for(i=0;i<n;i++)
			cin>>s[i];
		if(s[0][0] == '0')
		{
			cout<<"-1\n";
			continue;
		}
		int ans=0, t=0;
		for(i=0;i<n;)
		{
			t++;
			if(pos == n-1)
				break;
			if(t==500)
				{
					cout<<ans<<"\n";
					break;
				}
			pos=-1;
			for(j=i+1;j<=i+k && j<n;j++)
			{
				if(s[i][j] == '1' && s[j][j]=='1')
					pos=j;
			}
			if(pos != -1)
			{
				i=pos;
				ans++;
				continue;
			}
			else if(pos == -1)
			{
				for(j=i-1;j>=i-k && j>=0;j--)
				{
					if(s[i][j] == '1')
					{
						i=j;
						ans++;
						pos=j;
						break;
					}
				}
				if(pos == -1)
				{
					cout<<"-1\n";
					break;
				}
			}
		}
		if(pos!=-1)
			cout<<ans<<"\n";
	}
	return 0;
}