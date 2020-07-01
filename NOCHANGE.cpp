#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, n, p;
	cin>>t;
	while(t--) {
		bool flag=true;
		cin>>n>>p;
		ll temp=p;
		vector<ll> d(n);
		for(ll i=0; i<n; i++) {
			cin>>d[i];
			if(p%d[i]!=0)
				flag=false;
		}
		if(flag) {
			vector<ll> answer(n,0);
			vector<ll> sorted(n);
			// if((n==1) || (n==2 && (d[0]==1 || d[1]==1))) {
			// 	cout<<"NO\n";
			// 	continue;
			// }
			bool cond_no=true;
			for(int i=0; i<n; i++) {
				for(int j=i+1; j<n; j++) {
					if(max(d[j],d[i])%min(d[i],d[j])!=0) 
						cond_no=false;
				}
			}
			if(cond_no) {
				cout<<"NO\n";
				continue;
			}
			else {
			// 	ll ctr=0;
			// 	vector<ll> check(n,0);
			// 	for(int i=0; i<n; i++) {
			// 		for(int j=0; j<n; j++) {
			// 			if(j==i)
			// 				continue;
			// 			if(d[j]%d[i]==0)
			// 				check[i]++;
			// 		}
			// 	}
			// 	for(int i=0; i<n; i++) {
			// 		if(check[i]==0)
			// 			ctr++;
			// 	}
			// 	// if(ctr<2) {
			// 	// 	cout<<"NO\n";
			// 	// 	continue;
			// 	// }
			// 	//else {
			// 		cout<<"YES ";
			// 		for(int i=0; i<n; i++) {
			// 			if(check[i]==0) {
			// 				if(temp%d[i]==0) {
			// 					answer[i]++;
			// 					temp=temp-d[i];
			// 				}
			// 				else {
			// 					answer[i]=temp/d[i] + 1;
			// 				}
			// 			//}
			// 		}
			// 	}
			// }
				
				for(ll i=0;i <n; i++) 
					sorted[i]=d[i];
				sort(sorted.begin(),sorted.end(),greater<ll>());
				cout<<"YES ";
				for(ll i=0; i<n && temp>0; i++) {
					//answer[i]=temp/d[i]-1;
					if(sorted[i]==1)
						continue;
					if(temp%sorted[i]==0)
						answer[i]=temp/sorted[i]-1;
					else
						answer[i]=temp/sorted[i]+1;
					temp-=answer[i]*sorted[i];
				}
			}
			vector <ll>::iterator it;
			for(ll i=0;i<n;i++) {
				it=find(sorted.begin(), sorted.end(),d[i]);
				ll dis=distance(sorted.begin(),it);
				cout<<answer[dis]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			cout<<"YES ";
			vector<ll> an(n,0);
			bool isSimple=false;
			for(ll i=0; i<n; i++) {
				if(d[i]>p) {
					an[i]=1;
					isSimple=true;
					break;
				}
			}
			if(!isSimple) {
				for(ll i=0; i<n; i++) {
					if(p%d[i]==0)
						continue;
					else {
						an[i]=p/d[i]+1;
						break;
					}
				}
			}
			for(ll i=0; i<n; i++) 
				cout<<an[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}