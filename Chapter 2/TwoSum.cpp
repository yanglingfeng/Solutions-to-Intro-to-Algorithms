// Solving 2 sum in O(nlog(n)) time

#include <vector>
#include <iostream>
//#include "MergeSort.h"

using namespace std;

void merge(vector<int>& v, int begin, int mid, int end) {
	vector<int> v1, v2;
	for (int i = begin; i <= mid; i++) {
		v1.push_back(v[i]);
	}
	for (int i = mid + 1; i <= end; i++) {
		v2.push_back(v[i]);
	}

	int i = 0;
	int j = 0;
	int k = begin;
	while ((i < v1.size()) || (j < v2.size())) {
		if (j == v2.size()) {
			for (; i < v1.size(); i++, k++) {
				v[k] = v1[i];
			}
			break;
		}
		if (i == v1.size()) {
			for (; j < v2.size(); j++, k++) {
				v[k] = v2[j];
			}
			break;
		}

		if (v1[i] <= v2[j]) {
			v[k] = v1[i];
			++i;
		} else {
			v[k] = v2[j];
			++j;
		}
		++k;
	}
}

void merge_sort(vector<int>& v, int begin, int end) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		merge_sort(v, begin, mid);
		merge_sort(v, mid+1, end);
		merge(v, begin, mid, end);
	}
}

// return the index of the target if found in the vector; return -1 otherwise
int binary_search(const vector<int> v, int begin, int end, int target) {
	while (begin < end) {
		int mid = begin + (end - begin) / 2;
		if (v[mid] == target) 
			return mid;
		if (v[mid] < target) {
			begin = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return -1;
}

bool find_two_sum(vector<int>& v, int target) {
	merge_sort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size() - 1; i++) {
		if (binary_search(v, i, v.size() - 1, target - v[i]) != -1) 
			return true;
	}
	return false;
}

int main() {
	vector<int> v {1, 2, 3, 4, 5};
	if (find_two_sum(v, 6)) {
		cout << "Succeeded!" << endl;
	} else {
		cout << "Failed!" << endl;
	}
	return 0;
}