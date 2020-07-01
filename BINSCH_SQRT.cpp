#include <iostream>
using namespace std;

int main()
{
	int n, beg, end, mid;
	cin >> n;
	beg = 0;
	end = n;
	while(beg <= end)
	{
		mid = beg + (end - beg) / 2;
		if(mid * mid == n)
		{
			cout << mid << "\n";
			return 0;
		}
		if(mid * mid < n)
		{
			beg = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return 0;
}