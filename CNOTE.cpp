#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t,x,y,i,k,n;
	cin>>t;
	while(t--)
	{
		bool flag=false;
		cin>>x>>y>>k>>n;
		long p[n],c[n];
		for(i=0;i<n;i++)
		{
			cin>>p[i]>>c[i];
			if((c[i]<=k)&&(p[i]>=(x-y)))
			{
				flag=true;
			}
		}
		if(flag==true)
			cout<<"LuckyChef\n";
		else
			cout<<"UnluckyChef\n";
	}
	return 0;
}