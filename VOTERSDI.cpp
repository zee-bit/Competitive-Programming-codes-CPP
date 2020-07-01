/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x=5;
	int *ptr;
	*ptr=&x;
	printf("%d",printf("%d",ptr));
	return 0;
}*/

//-------------------------------------------------------

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
// 	int tree[][4]={
// 		{2},
// 		{3,4},
// 		{6,5,7},
// 		{4,1,8,3}};
// 	int s=0;
// 	for(int i=0;i<4;i++)
// 	{
// 		int min=1000007;
// 		for(int j=0;j<4;j++)
// 		{
// 			if(tree[i][j]<min && tree[i][j] != 0)
// 				min=tree[i][j];
// 		}
// 		s+=min;
// 	}
// 	cout<<s;
// 	return 0;
// }

//---------------------------------------------------------


// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
// 	bool test[10][10];
// 	memset(test, true, sizeof(test));
// 	for(int i=0;i<10;i++)
// 	{
// 		for(int j=0;j<10;j++)
// 		{
// 			cout<<test[i][j]<<" ";
// 		}
// 	}
// }

//-------------------------------------------------------------

//Sieve of Eratosthenes
// void sieveOfEratosthenes(int num)
// {
// 	bool prime[n+1];
// 	memset(prime, true, sizeof(prime)) //use cstring header
// 	for(int i=2;i*i<=num;i++)
// 	{
// 		if(prime[i])
// 		{
// 			for(int j=i*i;j<=n;j+=i)
// 				prime[j]=false;
// 		}
// 	}
// 	for(int i=0;i<n;i++)
// 		if(prime[i])
// 			cout<<i<<" ";
// }

//--------------------------------------------------------------------


