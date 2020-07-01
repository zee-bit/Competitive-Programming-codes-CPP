#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2, n3, i, id;
	cin>>n1>>n2>>n3;
	vector <int> idCont;
	for(i=0;i<(n1+n2+n3);i++)
	{
		cin>>id;
		idCont.push_back(id);
	}
	set<int> finalCount;
	sort(idCont.begin(),idCont.end());
	for(i=0;i<idCont.size();i++)
	{
		if(idCont[i] == idCont[i+1])
			finalCount.insert(idCont[i]);
	}
	int m=finalCount.size();
	cout<<m<<"\n";
	set<int>::iterator it;
	for( it=finalCount.begin();it != finalCount.end(); ++it)
		cout<<*it<<"\n";
	return 0;
}