#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string s[100];
		for(i=0;i<n;i++)
			cin>>s[i];
		int ans=0,weapons=0;
		for(i=0;i<10;i++)
		{
			weapons=0;
			for(j=0;j<n;j++)
			{
				if(s[j][i] == '1')
					weapons++;
			}
			if(weapons % 2 != 0 && weapons != 0)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}