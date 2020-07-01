#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long t,n,i,dif;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[100];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        dif=1000000001;
        for(i=0;i<n;i++){
            if(a[i+1]-a[i]<dif)
            {
                dif=a[i+1]-a[i];
            }
        }
        cout<<dif<<"\n";
    }
    return 0;
}

