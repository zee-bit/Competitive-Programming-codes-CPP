#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i, nd=0, mnd=0, pnd, max=0,lm=0, lmax=0, cntr=0;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++)
		cin>>a[i];
	for(i=0; i<n; i++)
	{
		if(a[i] == 1)
			nd++;
		else if(a[i] == 2)
		{
			if(nd>mnd)
			{
				mnd=nd;
				pnd=i;
			}
			nd--;
		}
	}
	for(i=0; i<n; i++)
	{
		if(a[i] == 1)
			cntr++;
		else
			cntr--;
		if(cntr > 0)
			lm++;
		if(cntr == 0)
		{
			lm++;
			if(lm>lmax)
			{
				lmax=lm;
				max=i-lmax+2;
			}
			lm=0;
		}
	}
	cout<<mnd<<" "<<pnd<<" "<<lmax<<" "<<max;
	return 0;
}