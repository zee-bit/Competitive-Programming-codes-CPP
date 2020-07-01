#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int l=s.length();
		int b=0,d=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='<')
				d++;
			else
				d--;
			if(d==0)
				b=i+1;
			else if(d<0)
				break;
		}
		cout<<b<<"\n";
	}
	return 0;
}