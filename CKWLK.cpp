#include <iostream>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		bool flag = true;
		cin>>n;
		while(n>0)
		{
			if((n % 10 == 0) && (n % 20 != 0))
				n/=10;
			else if((n % 20 == 0) || (n == 20))
				n/=20;
			else if((n % 10 == 0) && (n % 20 == 0))
				n/=10;
			else {
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"Yes\n";
		else 
			cout<<"No\n";
	}
	return 0;
}