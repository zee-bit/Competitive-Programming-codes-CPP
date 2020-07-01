#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,i;
	string s,tmp="";
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		tmp=s;
		int c=0;
		if(s[0]=='1')
		{
			s[1]='2';
			s[0]='2';
		}
		if(s[n-1]=='1')
		{
			s[n-2]='2';
			s[n-1]='2';
		}
		for(i=1;i<n-1;i++)
		{
			if((s[i]=='1')&&(tmp[i]=='1'))
			{
				s[i]='2';
				s[i+1]='2';
				s[i-1]='2';
			}
			else if((s[i]=='2')&&(tmp[i]=='1'))
			{
				s[i+1]='2';
				s[i-1]='2';
			}
		}
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
				c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}