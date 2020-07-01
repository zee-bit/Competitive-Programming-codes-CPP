#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, i, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int myArr[n][2];
		int ans=0;
		bool flag=true;
		for(i=0;i<n;i++)
		{
			cin>>myArr[i][0]>>myArr[i][1];
		}
		for(i=0;i<n-1;i++)
		{
			if(myArr[i][1]==myArr[i+1][0])
			{
				cout<<-1<<"\n";
				flag=false;
			}
			else if(myArr[i][1]>myArr[i+1][0] && (i+1)!=(n-1))
			{
				ans++;
			}
		}
		if(flag)
			cout<<ans<<"\n";
	}
	return 0;
}