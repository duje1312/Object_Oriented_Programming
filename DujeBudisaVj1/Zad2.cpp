#include"Vektor.h"
#include<iostream>
#include<vector>



using namespace std;

void vector_new(Vektor& vek,int velicina=1) {
	vek.niz = new int[velicina];
	vek.f_v = velicina;
	vek.l_v = 0;

}
void vector_delete(Vektor& vek) {
	delete[]vek.niz;
	vek.niz = nullptr;
	vek.f_v = 0;
	vek.l_v = 0;
}
void vector_push_back(Vektor& vek, int element) {
	if (vek.l_v == vek.f_v) {
		vek.f_v = vek.l_v * 2;
		int* n_niz = new int[vek.f_v];
		for (int i = 0; i < vek.l_v; i++) {
			n_niz[i] = vek.niz[i];
		}
		delete[] vek.niz;
		vek.niz = n_niz;
	}
	vek.niz[vek.l_v++] = element;
    }
	
void vector_pop_back(Vektor& vek) {
	if (vek.l_v > 0) {
		--vek.l_v;
	}
}
int vector_front(Vektor& vek) {
	if (vek.l_v > 0) {
		return vek.niz[0];
	}
}
int vector_back(Vektor& vek) {
	if (vek.l_v > 0) {
		return vek.niz[vek.l_v];
	}
}
int vector_size(Vektor& vek) {
	if (vek.l_v > 0) {
		return vek.l_v;
	}
}


int main(void) {

	Vektor vek;
	vector_new(vek, 10);
	vector_push_back(vek, 5);
	vector_push_back(vek, 8);
	vector_push_back(vek, 10);
	vector_push_back(vek, 50);
	for (int i = 0; i < vek.l_v;i++) {
		cout << vek.niz[i] << endl;
	};
	vector_pop_back(vek);
	cout << "nakon:" << endl;
	for (int i = 0; i < vek.l_v; i++) {
		cout << vek.niz[i] << endl;
	};

	

	return 0;
}