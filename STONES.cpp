#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i,t;
	string j,s;
	cin>>t;
	while(t--)
	{
		int c[26]={0};
		int cc[26]={0};
		int ans=0;
		cin>>j>>s;
		for(i=0;i<(int)j.length();i++)
		{
			if(((int)j[i]<=122)&&(((int)j[i]>=97)))
				c[(int)j[i]-97]=1;
			else if(((int)j[i]<=90)&&(((int)j[i]>=65)))
				cc[(int)j[i]-65]=1;
		}
		for(i=0;i<(int)s.length();i++)
		{
			if(((int)s[i]<=122)&&(((int)s[i]>=97)))
				if(c[(int)s[i]-97]==1)
					c[(int)s[i]-97]=-1;
			else if(((int)s[i]<=90)&&(((int)s[i]>=65)))
				if(cc[(int)s[i]-65]==1)
					cc[(int)s[i]-65]=-1;
		}
		for(i=0;i<26;i++)
		{
			if(c[i]==-1)
				ans++;
			if(cc[i]==-1)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}