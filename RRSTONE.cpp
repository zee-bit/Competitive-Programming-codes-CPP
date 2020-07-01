#include <iostream>
using namespace std;

int maximum(int a[], int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, i, j;
	cin>>n >> k;
	int a[100];
	for(i = 0; i < n; i++)
		cin>>a[i];
	if(k==0)
	{
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		return 0;
	}
	k%=2;
	if(k==0)
		k=2;
	for(i = 1; i <= k; i++)
	{
		int m=maximum(a, n);
		for(j = 0; j < n; j++)
		{
			a[j]=m-a[j];
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}


// #include <iostream>
// using namespace std;

// long long maximum(long long a[], long long n)
// {
// 	long long max=0;
// 	for(long long i=0;i<n;i++)
// 	{
// 		if(a[i]>max)
// 			max=a[i];
// 	}
// 	return max;
// }

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	long long n, k, i, j;
// 	cin>>n >> k;
// 	long long a[n];
// 	for(i = 0; i < n; i++)
// 		cin>>a[i];
// 	k%=3;
// 	if(k==0)
// 		k++;
// 	for(i = 1; i <= k; i++)
// 	{
// 		long long m=maximum(a, n);
// 		for(j = 0; j < n; j++)
// 		{
// 			a[j]=m-a[j];
// 		}
// 	}
// 	for(i=0;i<n;i++)
// 		cout<<a[i]<<" ";
// 	return 0;
// }


