#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string s,u;
	cin>>t;
	while(t--)
	{
		int f=0;
		cin>>s;
		int len=s.length();
		u=s;
		for(int l=1;l<=len;l++)
		{
			u=s;
			for(int r=l;r<=len;r++)
			{
				if(u[r-1]=='1') 
				{
					u[r-1]='0';
				}
				else 
				{
					u[r-1]='1';
				}
				for(int i=0;i<len-1;i++)
				{
					if(u[i]==u[i+1])
					{
						f++;
					}
				}
			}
		}
		cout<<f<<"\n";
	}
	return 0;
}