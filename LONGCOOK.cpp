#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long ll;

bool isLeapYear(ll year) {
    bool flag=false;
    if(year%100==0) {
        if(year%400==0) {
            flag=true;
        }
    } else if(year%4==0) {
        flag=true;
    }
    return flag;
}
ll firstDayOfMonth(ll year, ll month, ll day) {
  	ll a, y, m;
 	a=(14-month)/12;
  	y=year-a;
  	m=month+(12*a)-2;
  	return (day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// vector<int> offline(10000001,0);
	map<ll,ll> mp;
	int k=0;
	for(ll i=1;i<=10000000;) {
			if(firstDayOfMonth(i,2,1)==6 && !isLeapYear(i)) {
				mp[i]=k;
				k++;
				i++;
			}
			else if(!isLeapYear(i) && firstDayOfMonth(i,2,1)==0) {
				mp[i]=k;
				k++;
				i+=5;
			}
			else if(firstDayOfMonth(i,2,1)==6 && isLeapYear(i)) {
				mp[i]=k;
				k++;
				i+=5;
			}
			else 
			 	i++;
		} 
	ll t, m1, y1, m2, y2;
	cin>>t;
	while(t--) {
		// ll ans=0;
		cin>>m1>>y1;
		cin>>m2>>y2;
		// if(m1>2) 
		// 	y1++;
		// if(m2<2)
		// 	y2--;
		if(y1==y2 && mp.find(y1)==mp.end()) {
			cout<<"0\n";
			continue;
		}
		if(m1>2) {
			y1++;
		 	while(mp.find(y1)==mp.end())
		 		y1++;
		}
		else {
			while(mp.find(y1)==mp.end())
				y1++;
		}
		if(m2<2) {
		 	y2--;
		 	while(mp.find(y2)==mp.end())
		 		y2--;
		}
		else {
			while(mp.find(y1)==mp.end())
				y2--;
		}
		// for(ll i=y1;i<=y2;) {
		// 	if(firstDayOfMonth(i,2,1)==6 && !isLeapYear(i)) {
		// 		ans++;
		// 		i++;
		// 	}
		// 	else if(!isLeapYear(i) && firstDayOfMonth(i,2,1)==0) {
		// 		ans++;
		// 		i+=5;
		// 	}
		// 	else if(firstDayOfMonth(i,2,1)==6 && isLeapYear(i)) {
		// 		ans++;
		// 		i+=5;
		// 	}
		// 	else 
		// 		i++;
		// }
		
		cout<<abs(mp[y2]-mp[y1])+1<<"\n";
	}
}