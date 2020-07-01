#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

cpp_int gcd(cpp_int a, cpp_int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cpp_int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<gcd(a,b)<<"\n";
	}
	return 0;
}


