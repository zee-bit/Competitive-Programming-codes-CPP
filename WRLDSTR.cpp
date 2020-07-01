#include <iostream>
using namespace std;

int main()
{
	long t,n,i,l;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		l=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			{
				if(s[i]==s[i+1]){
					l=0;
					continue;
				}
				else if((i==n-1)&&(s[i]==s[i-1]))
				{
					continue;
				}
				l++;
			}
			else 
			{
				l=0;
			}
		}
		cout<<l<<"\n";
	}
	return 0;
}