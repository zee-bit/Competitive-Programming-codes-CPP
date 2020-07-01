#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,i,lmin,lbig;
	string m,w;
	cin>>t;
	while (t--)
	{
		cin>>m>>w;
		stack <char> st;
		string smaller,bigger;
		if(m.length()>w.length())
		{
			smaller=w;
			bigger=m;
		}
		else
		{
			smaller=m;
			bigger=w;
		}
		lmin=smaller.length();
		lbig=bigger.length();
		for(i=lmin-1;i>=0;i--)
		{
			st.push(smaller.at(i));
		}
		for(i=0;i<lbig;i++)
		{
			if(st.empty())  //important to check this				
			{               //condition before going forward!!
				break;
			}
			else if(bigger[i]==st.top())
			{
				st.pop();
			}
		}
		if(st.empty()==true)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}