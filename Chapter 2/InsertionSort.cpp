#include <vector>
#include <iostream>

using namespace std;

void sort(vector<int>& v) {
	if (v.empty()) {
		return;
	}
	for (int i = 1; i < v.size(); i++) {
		int tmp = v[i];
		int j = i - 1;
		while ((j >= 0) && (tmp < v[j])) {
			v[j+1] = v[j];
			--j;
		}
		v[j+1] = tmp;
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