#include <stdio.h> 
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
	int t, n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n==1) {
			printf("1\n1 1\n");
			continue;
		}
		printf("%d\n",n/2);
		if(n & 1) {
			printf("3 1 2 %d\n",n);
			--n;
		}
		else
			printf("2 1 2\n");
		auto start=high_resolution_clock::now();
		for(int i=3; i<n; i+=2) {
			//printf("2 %d %d\n",i,i+1);
			printf(" ");
		}
		auto stop=high_resolution_clock::now();
		auto duration=duration_cast<microseconds>(stop-start);
		cout<<duration.count();
	}
	return 0;
}