#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, l, r, i, cntr=1;
	cin>>n>>q;
	int a[n],peaks[n]={0};
	for(i=0;i<n;i++)
		cin>>a[i];
	peaks[0]=1;
	for(i=1;i<n;i++)
	{
		peaks[i]=cntr;
		if((a[i]>a[i+1]&&a[i]>a[i-1]) || (a[i]<a[i+1]&&a[i]<a[i-1]))
			cntr++;
	}
	while(q--)
	{
		cin>>l>>r;
		l--;
		r--;
		if(l == 0)
		{
			if((peaks[r]-peaks[l])%2==0)
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
		else if(r == n-1)
		{
			if((a[l]>a[l-1] && a[l]>a[l+1]) ||(a[l]<a[l-1] && a[l]<a[l+1]))
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"NO\n";
				else
					cout<<"YES\n";
			}
		}
		else
		{
			if(((a[l]>a[l-1] && a[l]>a[l+1]) || (a[l]<a[l-1] && a[l]<a[l+1])) && ((a[r]>a[r-1] && a[r]>a[r+1]) || (a[r]<a[r-1] && a[r]<a[r+1])))
			//if((peaks[r]!=peaks[r-1] || peaks[r]!=peaks[r+1])&&(peaks[l]!=peaks[l-1] || peaks[l]!=peaks[l+1]))
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else if((a[r]>a[r-1] && a[r]>a[r+1]) ||(a[r]<a[r-1] && a[r]<a[r+1]))
			//else if((peaks[r]!=peaks[r-1] || peaks[r]!=peaks[r+1])&&(peaks[l]==peaks[l-1] && peaks[l]==peaks[l+1]))
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"NO\n";
				else
					cout<<"YES\n";
			}
			else if((a[l]>a[l-1] && a[l]>a[l+1]) ||(a[l]<a[l-1] && a[l]<a[l+1]))
			//else if((peaks[r]==peaks[r-1] && peaks[r]==peaks[r+1]) && (peaks[l]==peaks[l-1] && peaks[l]==peaks[l+1]))
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else // if((peaks[r]==peaks[r-1] && peaks[r]==peaks[r+1]) && (peaks[l]!=peaks[l-1] || peaks[l]!=peaks[l+1]))
			{
				if((peaks[r]-peaks[l])%2==0)
					cout<<"NO\n";
				else
					cout<<"YES\n";
			}
		}
	}
	return 0;
}