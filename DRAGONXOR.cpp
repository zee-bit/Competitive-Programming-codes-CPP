#include<iostream>
#include<math.h>
using namespace std;
int sumOne(int n)
{
    int c=0;
    while(n/2>0)
    {
        if(n%2==1)
        c++;
        n=n/2;
    }
    if(n%2==1)
    c++;
    return c;
}
int main()
{
    int t,result;
    cin>>t;
    int a,b,s1,s2,s,n;
    while(t--)
    {
        cin>>n>>a>>b;
        s1=sumOne(a);
        s2=sumOne(b);
        s=s1+s2;
        if(s>n)
        {
            s=(2*n)-s;
        }
        result=0;
        while(s--)
        {
            result+=pow(2,n-1);
            n--;
        }
        cout<<result<<endl;
    }
}