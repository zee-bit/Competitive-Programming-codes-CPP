#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
int dayofweek(int d, int m, int y) {  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t; //count=0;
	cin>>t;
	while (t--) {
		int m1, y1, m2, y2;
		ll ans=0;
		cin>>m1>>y1;
		cin>>m2>>y2;
		if(m1>2)
			y1++;
		if(m2<2)
			y2--;
		ll apparent=((y2-y1)/400);
		//ll left=(y2-y1)%400;
		for(ll i=y1; i<y1+400; i++) {
			int day=dayofweek(1,2,i);
			if(day%7==6 || (day%7==0 && !(isLeapYear(i))))
				ans++;
		}
		ans=apparent*ans;
		//count=0;
		for(ll i=apparent*400+y1; i<=y2; i++) {
			int day=dayofweek(1,2,i);
			if(day%7==6 || (day%7==0 && !(isLeapYear(i))))
				ans++;
		}
		//ans+=count;
		cout<<ans<<"\n";
	}
	return 0;
}