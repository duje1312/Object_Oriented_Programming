#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
#include<math.h>

using namespace std;

void input_vector(vector<int>& vek) {
	while (true) {
		int broj;
		cout << "unesite znamenke vektora \n";
		cin >> broj;
		if (broj == 0) {
			break;
		}
		vek.push_back(broj);
	}
}

void print_vector(vector<int>& vek) {
	for (auto i : vek) {
		cout << " " << i <<" ";
	}
}
void make_uniqe(vector<int>& vek) {
	vector<int> novi;
	for(auto i:vek){
		if (find(novi.begin(), novi.end(), i) == novi.end()) {
			novi.push_back(i);
		}
		vek = novi;
	}
}
void sort_abs(vector<int>& vek) {
	sort(vek.begin(), vek.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});
	
}
int main(void) {

	vector<int> vek;
	input_vector(vek);
	cout << "ispis :" << endl;;
	print_vector(vek);
	make_uniqe(vek);
	cout << "\n";
	cout << "izbaceni duplikati :" << endl;
	print_vector(vek);
	sort_abs(vek);
	cout << "\n";
	cout << "sortirani" << endl;
	print_vector(vek);


	return 0;
}