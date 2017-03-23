#include <iostream>
#include <vector>
#include <algorithm> //for std::max

using namespace std;

int max_of_three(int a, int b, int c) {
	return max(a, b) > c ? max(a, b) : c;
}

// 1. Use DP
int find_maximal_subarray1(const vector<int>& v) {
	int maxSum = 0;
	int curSum = 0;

	int maxStartIndex = 0;

	for (int i = 0; i < v.size(); i++) {
		curSum += v[i];
		if (curSum < 0) {
			curSum = 0;
			maxStartIndex = i + 1;
		} else {
			maxSum = max(curSum, maxSum);
		}
	}

	return maxSum;
}

// 2. Use divide and conquer

int find_maximal_corssing(const vector<int>& v, int begin, int mid, int end) {
	int curSum = 0;
	int maxSum = 0;
	for (int i = mid; 0 =< i; i--) {
		curSum += v[i];
		maxSum = max(maxSum, curSum);		
	}
	curSum = max(maxSum, curSum);
	for (int i = mid + 1; i <= end; i++) {
		curSum += v[i];
		maxSum = max(maxSum, curSum);
	}
	return maxSum;

}

int find_maximal_subarray2(const vector<int>& v, int start, int end) {
	if (start == end) {
		return v[start];
	}
	int mid = start + (end - start) / 2;

	return max_of_three(find_maximal_subarray2(), find_maximal_subarray2(), find_maximal_crossing());
}

int main() {
	vector<int> v {4, -2, -8, 5, -2, 7, 7, 2, -6, 5};
	cout << find_maximal_subarray1(v) << endl;
}
