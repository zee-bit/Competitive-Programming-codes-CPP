//This is very important question with optimal 
//solution using Stacks.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin>>n;
    vector<ll> h(n);
    stack<ll> s;
    for(int i=0; i<n; i++)
        cin>>h[i];
    h.push_back(0);
    ll sum=0, i=0, area=0;
    while(i<h.size()) {
        if(s.empty() || h[i]>h[s.top()]) {
            s.push(i);
            i++;
        }
        else if(h[i]<h[s.top()]) {
            ll t=h[i];
            s.pop();
            area=max(area, h[i]*(s.empty()?i:i-s.top()-1));
        }
    }
    cout<<area<<"\n";
    return 0;
}
