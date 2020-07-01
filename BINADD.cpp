// #include <iostream>
// #include <sstream>
// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	string a,b;
// 	long long t,c=0,ai,bi;
// 	cin>>t;
// 	while(t--)
// 	{
// 		cin>>a>>b;
// 		stringstream ssa(a);
// 		stringstream ssb(b);
// 		ssa>>ai;
// 		ssb>>bi;
// 		while(bi>0)
// 		{
// 			long u=ai^bi;
// 			long v=ai&bi;
// 			ai=u;
// 			bi=v*2;
// 			c++;
// 		}
// 		cout<<c<<"\n";
// 		c=0;
// 	}
// 	return 0;
// }

// 
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	int t,n,i,k,mid;
// 	string s,temps="";
// 	cin>>t;
// 	while(t--)
// 	{
// 		cin>>n>>s;
// 		k=0;
// 		mid=n/2;
// 		temps=s.substr(0,mid);
// 		while(mid<n)
// 		{
// 			size_t found=str.find(temps,mid+1);
// 			if(found != string::npos) 
// 			{
// 				k++;
// 				mid=;
// 			}

// 		}

// 	}
// }

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cpp_int t,a,b,i;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		a=binaryToDecimal(a);
		b=binaryToDecimal(b);
		cpp_int u,v;
		while(b>0)
		{
			u=a^b;
			v=a&b;
			a=u;
			b=v*2;
			c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}
cpp_int binaryToDecimal(cpp_int n) 
{ 
    cpp_int num = n; 
    cpp_int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    cpp_int base = 1; 
  
    cpp_int temp = num; 
    while (temp) { 
        cpp_int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
}