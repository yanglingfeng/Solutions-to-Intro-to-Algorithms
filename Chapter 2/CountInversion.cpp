#include <vector>
#include <iostream>

using namespace std;

int merge(vector<int>& v, int begin, int mid, int end) {
	int numInversions = 0;

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
			numInversions += v1.size() - i;
			v[k] = v2[j];
			++j;
		}
		++k;
	}

	return numInversions;
}

int merge_sort(vector<int>& v, int begin, int end) {
	int numInversions = 0;
	if (begin < end) {
		int mid = (begin + end) / 2;
		numInversions += merge_sort(v, begin, mid);
		numInversions += merge_sort(v, mid+1, end);
		numInversions += merge(v, begin, mid, end);
	}
	return numInversions;
}

int findInversions(vector<int> v) {
	return merge_sort(v, 0, v.size()-1);
}

int main()
{
	vector<int> v {4, 3, 2, 1, 2, 0};
	cout << "We found " << findInversions(v) << " inversions" << endl;
	return 0;
}
