#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, time, mo, total_profit=0;
	char c;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<vector<int> > vec(4, vector<int>(4,0));
		//vector<int> visited(4,-1);
		for(int i=0; i<n; i++) {
			cin>>c>>time;
			mo=(int)c-65;
			time=time==12?0:time==3?1:time==6?2:3;
			vec[mo][time]++;
		}
		vector<int> store(4,0);
		int max=-10000;
		for(int i=0;i<4;i++) {
			//store[0]=vec[i][0];
			for(int j=0;j<4;j++) {
				if(j==i) 
					continue;
				//store[1]=vec[j][1];
				for(int k=0;k<4;k++) {
					if(k==j || k==i) 
						continue;
					//store[2]=vec[k][2];
					for(int l=0;l<4;l++) {
						if(l==k || l==j || l==i) 
							continue;
						//store[3]=vec[l][3];
						store[0]=vec[i][0];
						store[1]=vec[j][1];
						store[2]=vec[k][2];
						store[3]=vec[l][3];
						sort(store.begin(),store.end(),greater<int>());
						int sum=0, cost=100;
						for(int m=0;m<4;m++) {
							//cout<<store[m]<<" ";
							if(store[m]==0)
								sum-=100;
							else {
								sum+=store[m]*cost;
								cost-=25;
							}
						}
						//cout<<"\n";
						if(sum>max)
							max=sum;
					}
				}
			}
		}
		cout<<max<<"\n";
		total_profit+=max;
	}
	cout<<total_profit;
	return 0;
}