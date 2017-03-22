#include <iostream>
#include <vector>
#include <algorithm> //for std::max

using namespace std;

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
int find_maximal_subarray2(const vector<int>& v, int start, int end) {

}

int main() {
	vector<int> v {4, -2, -8, 5, -2, 7, 7, 2, -6, 5};
	cout << find_maximal_subarray1(v) << endl;
}