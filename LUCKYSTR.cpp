#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k,n,i;
	string s;
	cin>>k>>n;
	string a[k],b[n];
	for(i=0;i<k;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
	{
		if(b[i].length()>=47)
			cout<<"Good\n";
		else
		{
			int j;
			for(j=0;j<k;j++)
			{
				size_t found = b[i].find(a[j]);
				if(found != string::npos)
				{
					cout<<"Good\n";
					break;
				}
			}
			if(j == k)
				cout<<"Bad\n";
		}
	}
	return 0;
}