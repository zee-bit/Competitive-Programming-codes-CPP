#include <iostream>
using namespace std;

int main()
{
	long a,x=0,n,k,i;
	cin>>a>>n>>k;
	long c[k]={0};
	for(i=1;i<=a;i++)
	{
		if(c[x]<n)
			c[x]++;
		else 
		{
			c[x]=0;
			x++;
			while(true)
			{
				if(c[x]<n)
				{
					c[x]++;
					break;
				}
				else if((x==(k-1))&&(c[x]>n))
				{
					c[x]=0;
					break;
				}
				else
				{
					c[x]=0;
					x++;
				}
			}
			x=0;
		}
	}
	for(i=0;i<k;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}