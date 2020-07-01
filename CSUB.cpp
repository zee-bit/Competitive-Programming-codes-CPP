#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t,n,i;
	string s,str;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>s;
		for(i=0;i<n;i++)
		{
			if(s[i]=='1')
				ans++;
		}
		cout<<(ans*(ans+1)/2)<<"\n";
	}
	return 0;
}