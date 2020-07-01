#include <iostream>
using namespace std;

int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if (360 % n == 0)
			cout<<"y ";
		else 
			cout<<"n ";
		if(n<=360)
			cout<<"y ";
		else 
			cout<<"n ";
		if (n*(n+1)/2 <=360)
			cout<<"y ";
		else 
			cout<<"n ";
		cout<<"\n";
	}
}