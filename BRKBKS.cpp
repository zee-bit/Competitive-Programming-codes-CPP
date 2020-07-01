#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, s;
	cin>>t;
	while(t--)
	{
		int w1, w2, w3;
		cin>>s>>w1>>w2>>w3;
		if(w1 > w3)
			swap(w1,w3);
		if(w1 + w2 + w3 <= s)
			cout<<"1\n";
		else if(w1 + w2 <= s )
			cout<<"2\n";
		else
			cout<<"3\n";
	}
	return 0;
}