#include<iostream>
#include<vector>



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
		cout << "znamenka " << i << endl;
	}
}





int main(void) {

	vector<int> vek;
	input_vector(vek);
	cout << "print" << endl;
	print_vector(vek);
	return 0;
}