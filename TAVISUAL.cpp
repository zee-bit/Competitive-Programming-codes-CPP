#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,c,q;
		cin>>n>>c>>q;
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			if(c>=l && c<=r)
				c=l+r-c;
		}
		cout<<c<<"\n";
	}
	return 0;
}