#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, i, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n], count[11]={0};
		bool flag = true;
		for(i = 0; i < n; i++)
			cin>>a[i];
		for(i = 0; i < n - 1; i++)
		{
			if(abs(a[i]-a[i+1]) > 1)
			{
				flag = false;
				break;
			}
			else
			{
				count[a[i]]++;
			}
		}
		count[a[n-1]]++;
		for(i = 1; i <= 7; i++)
		{
			if((count[i] % 2 != 0 && i != 7) || count[i] == 0 || count[8] > 0 || count[9] > 0 || count[10] >0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}