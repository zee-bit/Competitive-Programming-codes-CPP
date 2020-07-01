#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;

	while(t--) {
		ll ans, N, tax;
		cin>>N;
		
		if(N<=250000)
		    tax=0.0;
		else if(N<=500000)
		    tax=0.05*(N-250000);
		else if(N<=750000)
		    tax=(0.05*250000)+(0.1*(N-500000));
	    else if(N<=1000000)
	        tax=(0.05*250000)+(0.1*250000)+(0.15*(N-750000));
	    else if(N<=1250000)
	        tax=(0.05*250000)+(0.1*250000)+(0.15*250000)+(0.2*(N-1000000));
	    else if(N<=1500000)
	        tax=(0.05*250000)+(0.1*250000)+(0.15*250000)+(0.2*250000)+(0.25*(N-1250000));
	    else
	        tax=(0.05*250000)+(0.1*250000)+(0.15*250000)+(0.2*250000)+(0.25*250000)+(0.3*(N-1500000));

		ans=N-tax;
		cout<<ans<<"\n";
	}
	return 0;
}