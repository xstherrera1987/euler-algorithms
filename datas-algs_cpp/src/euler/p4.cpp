/*
A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sys/time.h>
#include "../util.h"
using namespace std;
struct timeval str;
struct timeval fin;
void euler_p4() {
	gettimeofday(&str, 0);
	vector<int> *fact = NULL;
	vector<int> valid;
	int amt3dig;
	for (int i=999999; i>=0; i--) {
		if (is_palindrome( string_from_num(i) )) {
			if (!fact) delete fact;
			fact = factors_of(i);
			valid.clear();
			for (unsigned int j = 0; j<fact->size(); j++) {
				if ( digits_base10( (*fact)[j]) == 3 )
					valid.push_back( (*fact)[j]);
			}

			if ((amt3dig = valid.size()) >= 2) {
				for (int j=0; j<amt3dig; j++) {
					for (int k=0; k<amt3dig; k++) {
						if (j!=k && valid[j] * valid[k] == i) {
							cout << valid[j] << "*" << valid[k] << "=" << i << endl;
							gettimeofday(&fin, 0);
							int diff = fin.tv_sec > str.tv_sec ? fin.tv_usec - str.tv_usec + 1000000 : fin.tv_usec - str.tv_usec;
							cout << diff / 1000 << "ms" << endl;

							return;
						}
					}
				}
			}
		}
	}
}

