#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
int main()
{
	int t,i,ls;
	cin>>t;
	while(t--)
	{
		string s,cs="";
		cin>>s;
		ls=s.length();
		int k=1;
		for(i=0;i<ls;i++)
		{
			if(s[i]==s[i+1])
				k++;
			else
			{
				string to_k=patch::to_string(k);
				cs+=s[i-1]+to_k;
			}
		}
		if(cs.length()<s.length())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}