#include<iostream>
using namespace std;


typedef struct {
	int red;
	int stupac;
	float **element;
} matrica;

matrica napravi_matricu(int red, int stupac) {
	matrica mat;
	mat.red = red;
	mat.stupac = stupac;
	mat.element = new float* [ red ];
	for (int i = 0; i < red; i++) {
		mat.element[i] = new float[stupac];
	}
	return mat;

}

void unesi_elemente(matrica& mat,int a,int b) {
	int trenutni_broj = a;
	if (b < (mat.red) * (mat.stupac)) {
		cout << "nedovoljan ili prevelik broj elemenata" << "\t" << endl;
		return;
	}
	for (int i = 0; i < mat.red;i++) {
		for (int j = 0;j < mat.stupac;j++) {
			mat.element[i][j] = trenutni_broj++;
			if (trenutni_broj > b) {
				trenutni_broj = a;
			}
		}

	}

}
void ispisi_matricu(matrica& mat) {
	for (int i = 0; i < mat.red;i++) {
		for (int j = 0;j < mat.stupac;j++) {
			cout << mat.element[i][j] << "\t";
		}
		cout << endl;
	}
}
matrica zbroji(matrica& mat1, matrica& mat2) {
	matrica rezultat = napravi_matricu(mat1.red, mat1.stupac);
	
	for (int i = 0;i < mat1.red;i++) {
		for (int j = 0;j < mat1.stupac;j++) {
			rezultat.element[i][j] = mat1.element[i][j] + mat2.element[i][j];


		}
	}
	return rezultat;
}
matrica oduzmi(matrica& mat1, matrica& mat2) {
	matrica rezultat = napravi_matricu(mat1.red, mat1.stupac);
	for (int i = 0;i < mat1.red;i++) {
		for (int j = 0;j < mat1.stupac;j++) {
			rezultat.element[i][j] = mat1.element[i][j] - mat2.element[i][j];

		}
	}
	return rezultat;
}
matrica mnozenje(matrica& mat1,matrica& mat2)
{
	matrica rezultat = napravi_matricu(mat1.red,mat1.stupac);


	for (int i = 0; i < mat1.red; i++) {
		for (int j = 0; j < mat1.stupac; j++) {
			for (int k = 0; k < mat1.red; k++) {
				rezultat.element[i][j] = mat1.element[i][k] * mat2.element[k][j];
			}

		}
	}
	return rezultat;
}

matrica transp(matrica& mat1) {
	matrica rezultat = napravi_matricu(mat1.red, mat1.stupac);
	for (int i = 0;i < mat1.red;i++) {
		for (int j = 0;j < mat1.stupac;j++) {
			rezultat.element[i][j] = mat1.element[j][i];

		}
	}
	return rezultat;
}



int main(void) {
	int red, stupac;
	int raspon_a, raspon_b;
	int raspon_c, raspon_d;
	cout << "unesi red" << endl;
	cin >> red;
	cout << "unesi stupac" << endl;
	cin >> stupac;
	cout << "raspon prve matrice od:" << endl;
	cin >> raspon_a;
	cout << "raspon prve matricedo:" << endl;
	cin >> raspon_b;
	cout << "raspon druge od:" << endl;
	cin >> raspon_c;
	cout << "raspon druge do:" << endl;
	cin >> raspon_d;
	matrica mat;
	matrica mat1 = napravi_matricu(red, stupac);
	matrica mat2 = napravi_matricu(red, stupac);
	unesi_elemente(mat1,raspon_a,raspon_b);
	unesi_elemente(mat2,raspon_c,raspon_d);
	cout << "prva matrica\t" << endl;
	ispisi_matricu(mat1);
	cout << "druga matrica\t" << endl;
	ispisi_matricu(mat2);
	matrica rezultat_z = zbroji(mat1, mat2);
	cout << "rezultat zbrajanja\t" << endl;
	ispisi_matricu(rezultat_z);
	matrica rezultat_o = oduzmi(mat1, mat2);
	cout << "rezultat oduzimanja\t" << endl;
	ispisi_matricu(rezultat_o);
	matrica rezultat_mn = mnozenje(mat1, mat2);
	cout << "rezultat mnozenja\t" << endl;
	ispisi_matricu(rezultat_mn);
	matrica rezultat_transp = transp(mat1); //siti se ako os promini da transponiras drugu matricu samo u argumentu funkcije promini iz mat1 u mat2.
	cout << "ret za transportiranje\t" << endl;
	ispisi_matricu(rezultat_transp);


	return 0;
}
