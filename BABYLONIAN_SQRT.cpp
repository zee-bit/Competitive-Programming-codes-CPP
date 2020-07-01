#include <iostream>
using namespace std;

int main()
{
	float n, error=0.00001, x;
	cin>>n;
	x=n;
	while((x-n/x)>error)
	{
		x=(x+n/x)/2;
	}
	cout<<x<<"\n";
	return 0;
}