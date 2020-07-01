#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,k,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int w[100];
		for(i=0;i<n;i++)
		{
			cin>>w[i];
		}
		sort(w,w+n);
		int smin=0,smax=0;
		for(i=0;i<k;i++)
		{
			smin+=w[i];
		}
		for(i=k;i<n;i++)
		{
			smax+=w[i];
		}
		cout<<(abs(smax-smin))<<"\n";
	}
	return 0;
}