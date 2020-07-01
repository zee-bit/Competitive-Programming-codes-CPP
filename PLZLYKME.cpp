#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long l,t,d,s,c,ld,tn;
	cin>>t;
	while(t--)
	{
		cin>>l>>d>>s>>c;
		ld=s;
		tn=s;
		while(--d>0)
		{
			ld=s+(c*s);
			s=ld;
			if(ld>=l) {
				cout<<"ALIVE AND KICKING\n";
				break;
			}
		}
		if(ld==tn && ld>=l)
			cout<<"ALIVE AND KICKING\n";
		if(ld<l)
			cout<<"DEAD AND ROTTING\n";
	}
	return 0;
}