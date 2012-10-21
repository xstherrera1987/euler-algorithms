/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/
#include <vector>
#include "../util.h"
using std::vector;
void euler_p3() {
	long long n = 600851475143;
	vector<long long> *ret = prime_factors_of(n);
	cout << (*ret)[ret->size() -1] << endl;
}
