#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long n, m, q, mid, midA, midB;
	cin>>n>>m;
	if(n%2)
	{
		midA=(n+1)/2;
		midB=(3*n+1)/2;
		mid=midA+midB;
	}
	else
	{
		midA=n/2;
		midB=(3*n+2)/2;
		mid=midB+midA;
	}
	while(m--)
	{
		cin>>q;
		if(q<n+1)
		{
			cout<<0<<"\n";
			continue;
		}
		else
		{
			if(q<=mid)
				cout<<q-n-1<<"\n";
			else
				cout<<3*n-q+1<<"\n";
		}
	}
	return 0;
}