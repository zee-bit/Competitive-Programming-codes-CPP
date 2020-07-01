#include <iostream>
#include <algorithm>
using namespace std;

bool isDiv(int n)
{
	int d,s=0;
	while(n>0)
	{
		d=n%10;
		s+=d;
		n=n/10;
	}
	if(s%9==0)
		return true;
	return false;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int cost=0,left,right;
		cin>>n;
		left=n;
		right=n;
		if(isDiv(n))
		{
			cout<<cost<<"\n";
			continue;
		}
		else
		{
			while(1)
			{
				left-=1;
				if(isDiv(left))
				{
					cost=abs(n-left);
					cout<<cost<<"\n";
					break;
				}
				right+=1;
				if(isDiv(right))
				{
					cost=abs(right-n);
					cout<<cost<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}