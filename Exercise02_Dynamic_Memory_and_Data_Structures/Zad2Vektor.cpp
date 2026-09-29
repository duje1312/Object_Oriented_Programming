#include<iostream>
typedef struct {
	int* niz;
	int fvel;
	int lvel;
}vektor;

void vector_new(vektor& vek,size_t pocetna_vel = 1) {
	vek.niz = new int[pocetna_vel];
	vek.fvel = pocetna_vel;
	vek.lvel = 0;
}
void vector_delete(vektor& vek) {
	delete[] vek.niz;
	vek.niz = nullptr;
	vek.fvel = 0;
	vek.lvel = 0;
}
void vector_push_back(vektor& vek,int element) {
	if (vek.lvel == vek.fvel) {
		vek.fvel = vek.fvel * 2;
		int* n_niz = new int[vek.fvel];
		for (size_t i = 0;i < vek.lvel;i++) {
			n_niz[i] = vek.niz[i];
		}
		delete[] vek.niz;
		vek.niz = n_niz;
	}
	vek.niz[vek.lvel++] = element;
}
void vector_pop_back(vektor& vek){
if (vek.lvel > 0) {
	--vek.lvel;
	}
}
int vector_front(vektor& vek) {
	if (vek.lvel > 0) {
		return vek.niz[0];
	}
}
int vector_back(vektor& vek) {
	if (vek.lvel > 0) {
		return vek.niz[vek.lvel - 1];
	}
}

int vector_size(vektor& vek) {
	if (vek.lvel > 0) {
		return vek.lvel;
	}
}
int main(void) {

	vektor vek;
	vector_new(vek,2);
	vector_push_back(vek, 1);
	vector_push_back(vek, 4);
	vector_push_back(vek, 10);

	for (int i = 0;i < vek.lvel;i++) {
		std::cout << vek.niz[i] << std::endl;
	};
	std::cout << "Prvi element " << vector_front(vek) << std::endl;
	std::cout << "Zadnji element " << vector_back(vek) << std::endl;
	std::cout << "Velicina " << vector_size(vek) << std::endl;

	vector_pop_back(vek);
	for (int i = 0;i < vek.lvel;i++) {
		std::cout << vek.niz[i] << std::endl;
	};
	std::cout << "Umanjena velicina " << vector_size(vek) << std::endl;
	vector_delete(vek);






	return 0;
}