#include <iostream>
using namespace std;

int main()
{
	long n,s=0,i;
	cin>>n;
	long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	long check=(n*(n+1)/2);
	if(check==s)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}