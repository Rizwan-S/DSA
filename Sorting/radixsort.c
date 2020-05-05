#include<stdio.h>
int main(){
	int n, k;
	printf("Enter the number of elements:");
	scanf("%d", &n);
	printf("Enter the number of digits: ");
	scanf("%d", &k);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int b = 1, c[10], output[n];
	while(k--){
		for(int i = 0; i < 10; i++){
			c[i] = 0;
		}
		for(int i = 0; i < n; i++){
			c[( a[i] / b ) % 10]++;
		}
		for(int i = 1; i < 10; i++){
			c[i] = c[i] + c[i - 1];
		}
		for(int i = n - 1; i > -1; i--){
			output[--c[(a[i] / b) % 10]] = a[i];
		}
		for(int i = 0; i < n; i++){
			a[i] = output[i];
		}
		b *= 10;
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}