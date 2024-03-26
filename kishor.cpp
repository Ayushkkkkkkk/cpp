#include<stdio.h>
#include<math.h>
int main() {
	float area,pi=3.14,r;
	scanf("%f",&r);
	area=pi*pow(r , 2);
	printf("area of circle %6f = %6f",r,area);
	
}