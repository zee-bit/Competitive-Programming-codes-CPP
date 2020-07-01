#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, i, n;
	cin>>t;
	while(t--)
	{
		int min, ans=1;
		cin>>n;
		vector<int> speed(n);
		for(i=0;i<n;i++)
			cin>>speed[i];
		min=speed[0];
		for(i=1;i<n;i++)
		{
			if(speed[i]<min)
			{
				ans++;
				min=speed[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}