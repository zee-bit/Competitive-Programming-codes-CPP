#include <iostream>
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
		bool flag=false;
		cin>>s;
		for(i=0;i<(int)(s.length()-2);i++)
		{
			if(((s[i]=='1')&&(s[i+1]=='0')&&(s[i+2]=='1'))||((s[i]=='0')&&(s[i+1]=='1')&&(s[i+2]=='0')))
			{
				cout<<"Good\n";
				flag=true;
				break;
			}
		}
		if(flag==false)
			cout<<"Bad\n";
	}
	return 0;
}