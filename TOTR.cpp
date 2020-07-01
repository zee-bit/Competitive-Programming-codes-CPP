#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	unsigned int j,i;
	string m,s,eng="abcdefghijklmnopqrstuvwxyz",engstr="";
	bool up=false;
	cin>>t>>m;
	while(t--)
	{
		cin>>s;
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='_')
			{
				putchar(' ');
				continue;
			}
			else if(isupper(s[i]))
			{
				s[i]=(char)((int)s[i]+32);
				up=true;
			}
			else if(s[i]=='?'||s[i]=='.'||s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||(s[i]=='%')||(s[i]=='^')||(s[i]=='&')||(s[i]=='*')||(s[i]=='`')||(s[i]==',')||(s[i]==';')||(s[i]==':')||(s[i]=='/'))
			{
				putchar(s[i]);
				continue;
			}
			for(j=0;j<eng.length();j++)
			{
				if(s[i]==eng[j])
				{
					if(up)
					{
						putchar(toupper(m[j]));
						up=false;
						break;
					}
					else
					{
						putchar(m[j]);
						break;
					}
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}