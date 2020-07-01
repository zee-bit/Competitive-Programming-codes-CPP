#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, r, c;
	cin>>t;
	while(t--) {
		cin>>r>>c;
		vector<int> set_of_moves[18]={
				{8, 8},{7,7},{8, 6},{3,1},
				{4,2},{5,1},{8,4},{7,3},{8,2},
				{7,1},{1,7},{2,8},{3,7},{4,8},
				{1,5},{2,4},{1,3},{6,8}
		};
		if(r!=1 || c!=1) {
			if(r==c) {
				cout<<"19\n";
				cout<<"1 1\n";
			}
			else {
				cout<<"20\n";
				cout<<(r+c)/2<<" "<<(r+c)/2<<"\n";
				cout<<"1 1\n";
			}
		}
		else 
			cout<<"18\n";
		for(int i=0;i<18;i++) {
			for(int j=0; j<2; j++) {
				cout<<set_of_moves[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
