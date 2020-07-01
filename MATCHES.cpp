#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	int matches[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>t;
	while(t--)
	{
		int a, b, ans=0;
		cin>>a>>b;
		int s=a+b;
		while(s>0)
		{
			ans+=matches[s%10];
			s/=10;
		}
		cout<<ans<<"\n";
	}
	return 0;
}