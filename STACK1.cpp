#include <iostream>
#include <stack>
using namespace std;

int main()
{
	long long n,i;
	cin>>n;
	long long arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ans(arr,n);
	return 0;
} 
void ans(long long arr[], long long n)
{
	stack <long long> s;
	s.push(arr[0]);
	for(long long i=1;i<n;i++)
	{
		if(s.empty())
		{
			s.push(arr[i]);
			continue;
		}
		while(!(s.empty()) && (s.top<arr[i]))
		{
			s.pop();
			s.push(arr[i]);
		}
	}
}