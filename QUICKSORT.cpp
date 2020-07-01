#include <iostream>
using namespace std;

int Partition(int a[], int l, int h) {
	int pivot=a[l];
	int i=l, j=h-1;
	while(i<j) {
		while(a[i]<=pivot) 
			i++;
		while(a[j]>pivot) 
			j--;
		// do {
		// 	i++;
		// }while(a[i]<=pivot);
		// do {
		// 	j--;
		// }while(a[j]>pivot);
		if(i<j) 
			swap(a[i],a[j]); 
	}
	swap(a[l], a[j]);
	return j;
}

void quicksort(int a[], int l,int h) {
	if(l<h) {
		int j=Partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1, h);
	}
}

int main() {
	int a[]={34,56,23,6,33,9,2,5,21,5};
	quicksort(a,0,10);
	for(int i:a) {
		cout<<i<<" ";
	}
	return 0;
}