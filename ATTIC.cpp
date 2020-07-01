#include <iostream>
#include <string>
using namespace std;

int main()
{
	long t,i;
	string p;
	cin>>t;
	while(t--)
	{
		cin>>p;
		long len=p.length();
		long gap=0,ans=0,max=0;
		for(i=0;i<len;i++)
		{
			if(p[i]=='.' && gap==0)
				gap++;
			else if(p[i]=='.' && gap>0)
				gap++;
			else if(p[i]=='#' && gap>0)
			{
				if(gap>max)
				{
					ans++;
					max=gap;
				}
				gap=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}