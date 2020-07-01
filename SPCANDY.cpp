#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long n,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<n/k<<" "<<n%k<<"\n";
	}
	return 0;
}