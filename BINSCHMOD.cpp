#include <iostream>
using namespace std;

int main()
{
	int n,i;
	cin>>n;
	int a[100];
	for(i=0;i<n;i++)
		cin>>a[i];
	int mid,beg=0,end=n-1;
	while(beg <= end)
	{
		mid = beg + (end - beg)/2;
		if(a[mid]==mid)
		{
			cout<<mid<<"\n";
			return 0;
		}
		if(a[mid]<mid)
			beg=mid+1;
		else
			end=mid-1;
	}
	cout<<-1<<"\n";
	return 0;
}