struct Factorial {
	vector<ll> factorial;
	vector<ll> inverseFactorial;
	int modulo;

	ll modularBinaryExponentation(int base , int exponent) {
		if (exponent == 0) {
			return 1;
		}
		
		ll result = modularBinaryExponentation(base , exponent / 2);

		if (exponent % 2 == 1) {
			return (((result * result) % modulo) * base) % modulo;
		}
		else {
			return (result * result) % modulo;
		}
	}
	Factorial(int n , int _modulo) {
		factorial.resize(n + 1);
		inverseFactorial.resize(n + 1);
		modulo = _modulo;
		factorial[0] = 1;
		inverseFactorial[0] = 1;
		for (ll i = 1 ; i <= n ; i++){
			factorial[i] = (i * factorial[i-1]) % modulo;
			inverseFactorial[i] = modularBinaryExponentation(factorial[i] , modulo - 2);
		}
	}
	int FactorialOf(int x){
		return factorial[x];
	}
	int inverseOF(int x){
		return inverseFactorial[x];
	}
	int binomialCofficientOf(int a , int b){
		return (((factorial[a] * inverseFactorial[a - b]) % modulo) * inverseFactorial[b]) % modulo;
	}
	
	int multinomialCoefficientOf(vector<int> &buckets){
		int sum = 0 ;
		for (int bucket : buckets){
			sum += bucket;
		}
		ll result = FactorialOf(sum);
		
		for (int bucket : buckets)
			result = (result * inverseOF(bucket)) %  modulo;
		return result;
	}
};