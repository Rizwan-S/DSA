#include<stdio.h>

int main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d\n", &n);
	int a[n], output[n], max = -1000;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if( a[i] > max){
			max = a[i];
		}
	}
	int count[max + 1];
	for(int i = 0; i <= max; i++){
		count[i] = 0;
	}
	for(int i = 0; i < n; i++){
		count[a[i]]++;	
	}
	for(int i = 1; i < max + 1; i++){
		count[i] = count[i] + count[i - 1];
	}
	for(int i = n - 1; i > -1; i--){
		output[--count[a[i]]] = a[i];
	}
	for(int i = 0; i < n; i++){
		printf("%d ", output[i]);
	}
}
