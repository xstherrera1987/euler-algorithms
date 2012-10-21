#include <algorithm>
#include <vector>
#include "../util.h"
using namespace std;

/* make min heap w int[] by using std::greater */
/* make max heap w int[] by using std::less (DEFAULT) */
inline void heap_operations() {
	int sz = 10;
	int *val = randarr(sz,1,100);
	//printarr(val, 0, sz);

	// max heap
	make_heap(val, val+sz, less<int>());
	//printarr(val, 0, sz);

	// using vector now to facilitate insertion (and array resizing)
	vector<int> v(val, val+sz);

	// push data to array, heapify
	v.push_back(200);
	push_heap(v.begin(), v.end());
	v.push_back(-100);
	push_heap(v.begin(), v.end());
	v.push_back(0);
	push_heap(v.begin(), v.end());
	v.push_back(-300);
	push_heap(v.begin(), v.end());

	// raw order
	printarr(&v[0], 0, v.size());

	// pop_heap moves the value at beginning to (end-1)
	// popping all elements (for printing) actually reverses the heap
	// pop_heap does not affect vector::size()

	printheap(&v[0], 0, v.size(), true);
	// raw order
	printarr(&v[0], 0, v.size());

	// min heap
	make_heap(v.begin(), v.end(), greater<int>());
	// raw order
	printarr(&v[0], 0, v.size());
	// popping all elements (for printing) again reverses the heap
	printheap(&v[0], 0, v.size(), false);

	// back in max heap order
	printarr(&v[0], 0, v.size());
}
