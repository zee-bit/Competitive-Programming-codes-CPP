#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,i, j=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	vector <vector <int> > perm;
	bool chk[n]={false};
	for(j=0;j<n;j++) {
		if(!chk[j]) {
			vector <int> v;
			v.push_back(j+1); chk[j]=true;
			int x=a[j];
			while(1) {
				v.push_back(x); chk[x-1]=true;
				if(x==v[0])
					break; 
				x=a[x-1];
			}
			perm.push_back(v);
		}
	}
	cout<<perm.size()<<"\n";
	for(i=0;i<perm.size();i++) {
		for(int j=0;j<perm[i].size();j++)
			cout<<perm[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}