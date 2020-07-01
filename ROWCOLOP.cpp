#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, i, x, indx;
	cin>>n>>q;
	int myArrRow[n]={0}, myArrCol[n]={0};
	while(q--)
	{
		string s;
		cin>>s>>indx>>x;
		if(s=="RowAdd")
		{
				myArrRow[indx-1]+=x;
		}
		else if(s=="ColAdd")
		{
				myArrCol[indx-1]+=x;
		}
	}
	int maxR=0,maxC=0;
	for(i=0;i<n;i++)
	{
		if(myArrRow[i]>maxR)
			maxR=myArrRow[i];
		if(myArrCol[i]>maxC)
			maxC=myArrCol[i];
	}
	cout<<maxR+maxC;
	return 0;
}