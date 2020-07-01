#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		int s, a, b, result, d, rem;
		cin>>n>>a;
		int max = pow(10,n) - 1;
		s = 2 * max + a + 2;
		cout<<s<<endl;
		cin>>b;
		rem = s - a - b;
		if(rem > (2 * max))
		{
			cout<<max<<endl;
			rem = rem - max;
		}
		else if(rem <= (2 * max) && rem > max)
		{
			cout<<rem - max - 1<<endl;
			rem = max + 1;
		}
		cin>>d;
		rem -= d;
		cout<<rem<<"\n";
		cin>>result;
		if(result == -1)
			return 0;
	}
	return 0;
}