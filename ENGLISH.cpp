#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, i;
	string wrd;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector <string> words;
		for(i=0;i<n;i++)
		{
			cin>>wrd;
			words.push_back(wrd);
		}
		sort(words.begin(),words.end());
		for(i=0;i<n;i++)
			cout<<words[i]<<"  ";
		// int beauty=0;
		// if(n == 1)
		// {
		// 	cout<<"0\n";
		// 	continue;
		// }
		// for(i=0;i<n-1;i+=2)
		// {
		// 	int lp=0, ls=0, j, minl, k=1;
		// 	int first=words[i].length(), second=words[i+1].length();
		// 	minl = min(first,second);
		// 	for(j=0;j<minl;j++)
		// 	{
		// 		if(words[i][j] == words[i+1][j])
		// 			lp++;
		// 		else
		// 			break;
		// 	}
		// 	while(true)
		// 	{
		// 		if(words[i][words[i].length()-k] == words[i+1][words[i+1].length()-k])
		// 		{
		// 			ls++;
		// 			k++;
		// 		}
		// 		else
		// 			break;
		// 	}
		// 	beauty=beauty+(pow(min(ls,lp),2));
		// }
		// cout<<beauty<<"\n";
	} 
	return 0;
}