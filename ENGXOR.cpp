#include <bits/stdc++.h>
using namespace std;

#define P2(n) n, n ^ 1, n ^ 1, n 
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n) 
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n) 
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

unsigned int table[256] = { LOOK_UP }; 
 
int Parity(int num) 
{ 
    int max = 16; 
    while (max >= 8) { 
        num = num ^ (num >> max); 
        max = max / 2; 
    }  
    return table[num & 0xff]; 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, q;
	cin>>t;
	while(t--) {
		cin>>n>>q;
		vector<int> a(n), p(q);
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<q; i++)
			cin>>p[i];
		int even_o=0, odd_o=0, even_e=0, odd_e=0;
		
		//FOR EVEN PARITY P
		for(int i=0; i<n; i++) {
			bool res=Parity(3^a[i]);
			res?odd_e++:even_e++;
		}
		//FOR ODD PARITY P
		for(int i=0; i<n; i++) {
			bool res=Parity(2^a[i]);
			res?odd_o++:even_o++;
		}
		for(int i=0; i<q; i++) {
			bool res=Parity(p[i]);
			if(res)
				cout<<even_o<<" "<<odd_o<<"\n";
			else
				cout<<even_e<<" "<<odd_e<<"\n";
		}
	}
	return 0;
}