#include <vector>
#include <iostream>

using namespace std;

void sort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int curMin = i;
		for (int j = i+1; j < v.size(); j++) {
			if (v[j] < v[curMin]) {
				curMin = j;
			}
		}
		int temp = v[i];
		v[i] = v[curMin];
		v[curMin] = temp;
	}
}

int main()
{
	vector<int> v {4, 3, 2, 1, 2, 0};
	sort(v);
	cout << "After sorting..." << endl;
	for (const auto& i: v)
  		cout << i << ' ';
  	cout << endl;
	return 0;
}