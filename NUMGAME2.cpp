#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,t,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==1)
			cout<<"ALICE\n";
		else
			cout<<"BOB\n";
	}
	return 0;
}