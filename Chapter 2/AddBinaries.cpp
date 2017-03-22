#include <vector>
#include <iostream>
using namespace std;

// did not handle overflow
vector<int> add(const vector<int> v1, const vector<int> v2) {
	vector<int> res(v1.size()+1, 0);
	int carry = 0;
	for (int i = v1.size(); i >= 0; i--) {
		carry += (v1[i] + v2[i]);
		res[i+1] = carry % 2;
		carry /= 2;
	}
	if (carry) 
		res[0] = 1;
	return res;
}

int main()
{
	vector<int> v1 {0, 1, 1, 1, 1, 0};
	vector<int> v2 {1, 0, 1, 0, 0, 1};

	auto res = add(v1, v2);
	cout << "After addition..." << endl;
	for (const auto& i: res)
  		cout << i << ' ';
  	cout << endl;
	return 0;
}
