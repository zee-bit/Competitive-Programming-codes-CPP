#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long n,x1,x2,x3,y1,y2,y3,i,count=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if(((y1-y2)*(y2-y3) == -(x1-x2)*(x2-x3))||((y2-y3)*(y3-y1) == -(x2-x3)*(x3-x1))||((y3-y1)*(y1-y2) == -(x3-x1)*(x1-x2)))
			count++;
	}
	cout<<count;
	return 0;
}