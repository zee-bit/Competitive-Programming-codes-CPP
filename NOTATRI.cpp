#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j;
	while(1)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int ans = 0;
		cin>>n;
		if(n == 0)
			return 0;
		int len[20000];
		for(i = 0; i < n; i++)
			cin>>len[i];
		sort(len, len+n);
		for(i = 0; i < n - 1; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				int m;
				m = upper_bound(len, len + n, len[i] + len[j]) - len;
				ans += n - m;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}