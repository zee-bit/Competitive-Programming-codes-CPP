#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int sum=0;
		for(i=0;i<s.length();i++)
		{
			if(isalpha(s[i])==0)
				sum=sum+((int)s[i] - 48);
		}
		cout<<sum<<"\n";
	}
	return 0;
}