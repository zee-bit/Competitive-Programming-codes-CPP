#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, time, m, total_profit=0;
	char c;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<vector<int> > vec(4, vector<int>(4,0));
		vector<int> visited(4,-1);
		for(int i=0; i<n; i++) {
			cin>>c>>time;
			m=(int)c-65;
			time=time==12?0:time==3?1:time==6?2:3;
			vec[m][time]++;
		}
		vector<int> max(4,0);
		for(int j=0;j<4;j++) {
			for(int i=0; i<4; i++) {
				if(vec[i][j] > max[j]) {
					vector<int> :: iterator it=find(visited.begin(),visited.end(), i);
					if(it != visited.end()) {
						int dis=distance(visited.begin(),it);
						if(max[dis]<vec[i][j]) {
							int max1=0;
							for(int k=0; k<4; k++) {
								if(find(visited.begin(),visited.end(),k)!=visited.end())
									continue;
								if(vec[k][dis]>max1) {
									max1=vec[k][dis];
									visited[dis]=k;
								}
							}
							max[dis]=max1;
							max[j]=vec[i][j];
							visited[j]=i;
							//visited[dis]=-1;
							continue;
						}
						else
							continue;
					}
					max[j]=vec[i][j];
					visited[j]=i;
				}
			}
		}
		sort(max.begin(),max.end(),greater<int>());
		int profit=0, money=100;
		for(int i=0; i<4; i++) {
			if(max[i]==0) {
				profit=profit-100;
				continue;
			}
			profit=profit+(max[i]*money);
			money-=25;
		}
		cout<<profit<<"\n";
		total_profit+=profit;
	}
	cout<<total_profit;
	return 0;
}