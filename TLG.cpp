#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, w, l = 0, s, t;
	cin>>n;
	while(n--)
	{
		cin>>s>>t;
		if(s - t > 0 && abs(s - t) > l)
		{
			l = abs(s - t);
			w = 1;
		}
		else if(s - t < 0 && abs(s - t) > l)
		{
			l = abs(s - t);
			w = 2;
		}
		else if(abs(s-t) == l)
		{
			
		}
	}
	cout<<w<<" "<<l;
	return 0;
}