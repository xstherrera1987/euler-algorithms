#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

#ifndef UTIL_H
#define UTIL_H

using namespace std;
inline int* randarr(int size, int min, int max) {
	int *ret = new int[size];
	for (int i=0; i<size; i++)
		ret[i] = (int) (((double) rand() / RAND_MAX) * max) + min;
	return ret;
}
template<typename T> inline void printarr(T* v, int begin, int end) {
	for (int i=begin; i<end; i++)
		cout << v[i] << " ";
	cout << endl;
}
// end should point to one passed the last element, max= maxheap vs minheap
template<typename T> inline void printheap (T* v, int begin, int end, bool max) {
	end--;
	while (end>=begin) {
		cout << v[begin] << " ";
		if (max) pop_heap(&v[begin], &v[end+1], less<T>() );
		else pop_heap(&v[begin], &v[end+1], greater<T>() );
		end--;
	}
	cout << endl;
}
// optimized naive algorithm
inline bool is_prime(int n) {
	if (n == 2 || n == 3 || n == 5) return true;
	if (n <= 1 || (n&1) == 0) return false;

	for (int i = 3; i*i <= n; i += 2)
		if (n % i == 0) return false;

	return true;
}
// repeatedly divides num by each integer ascending
template <typename T> inline vector<T>* prime_factors(T num) {
	vector<T> ret = new vector<T>();
	for (int i=2; i <= num; i++) {
		while(num % i == 0) {
			num /= i;
			ret.push_back(i);
		}
	}
	return ret;
}
inline bool is_palindrome(string s) {
	int len = s.size();
	int halflen = len/2;
	int j = len - 1;
	for (int i=0; i<halflen; i++) {
		if (s[i] != s[j]) return false;
		j--;
	}
	return true;
}
template <typename T> inline int num_digits(T n) {
	return 1 + (T) log10(n);
}
template <typename T> inline vector<T>* prime_factors_of(T n) {
	vector<T> *ret = new vector<T>();
	for (T i=2; i<=n; i++) {
		while (n % i == 0) {
			n /= i;
			ret->push_back(i);
		}
	}
	return ret;
}
template <typename T> inline vector<T>* factors_of(T n) {
	vector<T>* ret = new vector<T>();
	for (T i=1; i<=n; i++)
		if(n%i == 0)
			ret->push_back(i);
	return ret;
}
template <typename T> inline int digits_base10(T n) {
	return 1 + ((T) log10(n));
}
inline int chars_in_string(char c, string s) {
	int letters[26];
	char k;
	for (unsigned int i=0; i<s.length(); i++) {
		k = s[i];
		if ( (k>'A' && k<'Z') || (k>'a' && k<'z') ) {
    		if (k>'A' && k<'Z') letters[k-'A']++;
    		else letters[k-'a']++;
		}
	}
	if (c>'A' && c<'Z') return letters[c-'A'];
	else return letters[c-'a'];
}
// little-endian
template <typename T> inline char* get_binary_string(T n) {
	int len = sizeof(T);
	char *ret = new char[len];
	for (int i=0; i<len; i++) {
		ret[i] = (n&1)==1 ? '1' : '0';
		n = n >> 1;
	}
	return ret;
}
// returned in big-endian format for printing
inline char* get_printable_binary_string(int n) {
	int len = sizeof(int);
	char *ret = new char[len];
	for (int i=len-1; i>=0; i--) {
		ret[i] = (n&1)==1 ? '1' : '0';
		n = n >> 1;
	}
	return ret;
}
template<typename T> inline const char* string_from_num(T n) {
	string res;
	ostringstream oss;
	oss << n;
	return oss.str().c_str();
}
// Greatest Common Divisor = Greatest Common Factor = Euclid's Algorithm
template <typename T> inline T gcd(T a, T b) {
	T t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}
// Least Common Multiple for two numbers
template <typename T> T inline lcm(T a, T b) {
	if (a < b) {
		return ( a / gcd(a,b) * b);
	} else {
		return ( b / gcd(a,b) * a);
	}
}
#endif
