#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,v,s;
	double time;
	cin>>t;
	while(t--)
	{
		cin>>s>>v;
		time=((2.0*s)/(3.0*v));
		printf("%0.6f \n",time);
	}
	return 0;
}