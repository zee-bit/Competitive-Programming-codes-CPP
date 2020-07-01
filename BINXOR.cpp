// #include <iostream>
// using namespace std;

// int main()
// {
// 	long t,n,i;
// 	string a,b;
// 	cin>>t;
// 	while(t--)
// 	{
// 		cin>>n>>a>>b;
// 		long a0=0,a1=0,b0=0,b1=0;
// 		for(i=0;i<n;i++)
// 		{
// 			if(a[i]=='0')
// 				a0++;
// 			if(b[i]=='0')
// 				b0++;
// 		}
// 		a1=n-a0;
// 		b1=n-b0;
// 	}
// }

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string a, b;
	char c[100];
	cin >> a >> b;
	for( unsigned int i = 0; i < a.length(); i++)
	{
		c[i] = (a[i] - '0')^(b[i] - '0');
		cout << c[i];
	}
	return 0;
}