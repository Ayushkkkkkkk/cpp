// CPP program to find MSB
// number for a given POSITIVE n.
#include <bits/stdc++.h>
using namespace std;

long long double setBitNumber(long long double n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}

// Driver code
int main()
{
	long long double n = 3.0;
	cout << setBitNumber(n);
	
}
