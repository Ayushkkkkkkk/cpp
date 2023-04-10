#include<stdio.h>

const int N = 1e4 + 10;
int a[N];

int main(){
	int n ; scanf("%d" , &n);
	for(int i = 0 ; i < n; i++){
		scanf("%d" , &a[i]);
	}
	for(int i = 0 ; i < n; i++){
		printf("%d\n" , a[i]);
	}
}