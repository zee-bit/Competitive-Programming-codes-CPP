#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n!=0) {
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		stack<int> st;
		int k=1;
		for(int i=0; i<n; i++) {
			while(!st.empty()&&st.top()==k) {
				st.pop();
				k++;
			}
			if(a[i]==k)
				k++;
			else
				st.push(a[i]);
		}
		while(!st.empty()&&st.top()==k) {
			st.pop();
			k++;
		}
		if(st.empty()) 
			cout<<"yes\n";
		else
			cout<<"no\n";
		cin>>n;
	}
	return 0;
}