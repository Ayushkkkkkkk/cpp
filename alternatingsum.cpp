// C++ program to find sum of maximum
// sum alternating sequence starting with
// first element.
#include <bits/stdc++.h>
using namespace std;

// Return sum of maximum sum alternating
// sequence starting with arr[0] and is first
// decreasing.
int maxAlternateSum(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	// handling the edge case
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	if (min == arr[0]) {
		return arr[0];
	}
	// create two empty array that store result of
	// maximum sum of alternate sub-sequence

	// stores sum of decreasing and increasing
	// sub-sequence
	int dec[n];
	memset(dec, 0, sizeof(dec));

	// store sum of increasing and decreasing sub-sequence
	int inc[n];
	memset(inc, 0, sizeof(inc));

	// As per question, first element must be part
	// of solution.
	dec[0] = inc[0] = arr[0];

	int flag = 0;

	// Traverse remaining elements of array
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// IF current sub-sequence is decreasing the
			// update dec[j] if needed. dec[i] by current
			// inc[j] + arr[i]
			if (arr[j] > arr[i]) {
				dec[i] = max(dec[i], inc[j] + arr[i]);

				// Revert the flag , if first decreasing
				// is found
				flag = 1;
			}

			// If next element is greater but flag should be
			// 1 i.e. this element should be counted after
			// the first decreasing element gets counted
			else if (arr[j] < arr[i] && flag == 1)

				// If current sub-sequence is increasing
				// then update inc[i]
				inc[i] = max(inc[i], dec[j] + arr[i]);
		}
	}

	// find maximum sum in b/w inc[] and dec[]
	int result = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (result < inc[i])
			result = inc[i];
		if (result < dec[i])
			result = dec[i];
	}

	// return maximum sum alternate sub-sequence
	return result;
}

// Driver program
int main()
{
	int arr[] = {1 , 3 , 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum sum = " << maxAlternateSum(arr, n)
		<< endl;
	return 0;
}
