#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,i,num;
	cin>>t;
	while(t--)
	{
		int a[101]={0};
		int max=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>num;
			a[num]++;
		}
		for(i=1;i<=100;i++)
		{
			if(a[i]>max)
				max=a[i];
		}
		cout<<(n-max)<<"\n";
	}
	return 0;
}