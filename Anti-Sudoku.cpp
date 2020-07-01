#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		vector<string> board(9);
		for(int i=0; i<9; i++) 
			cin>>board[i];
		int reg=0, k=0;
		for(int i=0; i<9; i++) {
			if(i%3==0) {
				reg=0; 
				reg+=k++;
			}
			if(board[i][reg]=='9')
				board[i][reg]='1';
			else
				board[i][reg]=char(board[i][reg]+1);
			reg+=3;
		}
		for(int i=0; i<9; i++) 
			cout<<board[i]<<"\n";
	}
	return 0;
}