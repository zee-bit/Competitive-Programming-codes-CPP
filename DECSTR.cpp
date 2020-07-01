#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t,i,k;
	string s="";
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k<=25)
		{
			for(i='a';i<=('a'+k);i++)
			{
				s=(char)i+s;
			}
			cout<<s<<"\n";
			s="";
		}
		else
		{
			s="zyxwvutsrqponmlkjihgfedcba";
			int n=25-(k%25);
			int p=k/25;
			if(n!=25)
				cout<<s.substr(n,s.length());
			while(p--)
				cout<<s;
			cout<<"\n";
		}
		s="";
	}
	return 0;
}