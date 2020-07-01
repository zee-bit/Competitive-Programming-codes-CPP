#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, m, n, i, j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int a[n][m];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		if(n<3 || m<3)
			cout<<(n*m)<<"\n";
		else
		{
			int result = n*m, k=1;
			int o = min(m,n);
			if(o%2==0)
				o--;
			o/=2;
			for(k=1;k<=o;k++)
			{
				for(i=k;i<n-k;i++)
				{
					for(j=k;j<m-k;j++)
					{
						bool flag = true;
						for(int l=1;l<=k;l++)
						{
							if(a[i-l][j]==a[i+l][j] && a[i][j-l]==a[i][j+l])
								continue;
							else 
							{
								flag=false;
								break;
							}
						}
						if(flag)
							result++;				
					}
				}
			}
			cout<<result<<"\n";
		}
	}
	return 0;
}