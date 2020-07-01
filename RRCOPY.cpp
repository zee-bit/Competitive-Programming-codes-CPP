#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		vector <int> v;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		v.push_back(a[0]);
		int c=1;
		vector <int>::iterator it;
		for(i=1;i<n;i++)
		{
			it=find(v.begin(),v.end(),a[i]);
			if(it==v.end())
			{
				c++;
				v.push_back(a[i]);
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}