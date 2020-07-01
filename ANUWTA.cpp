#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long t,n,s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		if(n==0){
			cout<<n<<"\n";
			continue;
		}
		else{
			s=n+((n*(n+1))/2);
			cout<<s<<"\n";
		}
	}
	return 0;
}