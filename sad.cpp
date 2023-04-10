#include <iostream>
#include<vector>
using namespace std;
// find way to seperate three greatest numbers in an array


void swap(int a , int b) {
	int temp = a; //swap them
	a = b;
	b = temp;
}

int sortA(int n, int arr[]) {
	int temp, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (arr[j] > arr[i]) {
				 temp = arr[i]; //swap them
				  arr[i] = arr[j];
                  arr[j] = temp;
			}
		}
	}
}

int main() {
	int n ; cin >> n;
	int arr[n];
	for (int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	sortA(n, arr);
	int first , second , third;
	first = arr[n - 1];
	second = arr[n - 2];
	third = arr[n - 3];
	cout << first << " " << second << " " << third << endl;
}