#include<iostream>
#include<string>
#include<algorithm>
#include<vector>



using namespace std;	

class container {
private:
	int* niz;
	int fiz;
	int lvel;
public:
	container() :niz(nullptr),fiz(0),lvel(0) {};
	container(container& kopija) :niz(kopija.niz), fiz(kopija.fiz), lvel(kopija.lvel) {};
	container(container&& kopija) :niz(move(kopija.niz)),fiz(move(kopija.fiz)), lvel(move(kopija.lvel)) {
		kopija.niz = nullptr;
		kopija.lvel = 0;
		kopija.fiz = 0;
	};
	void push_back(int broj) {
		if(lvel==0){
			lvel = 1;
			niz = new int[lvel];
		}
		if (fiz == lvel) {
			int novi_vel = 2*lvel;
			int* novi_niz = new int[novi_vel];
			for (int i = 0; i < fiz; i++) {
				novi_niz[i] = niz[i];	
			}
			delete[]niz;
			niz = novi_niz;
			lvel=novi_vel;
		}
		
		niz[fiz++] = broj;	
	};
	int size() const {
		return fiz;
	};
	int capacity() const{
		return lvel;
	};
	int at(int lokacija) {
		if (niz == nullptr) {
			return 0;
		}
		else {
			return niz[lokacija];
		}
	}
	int clear() {
		delete[]niz;
		fiz = 0;
		lvel = 0;
	}
};















int main(void) {


	container c;
	
	c.push_back(10);
	c.push_back(20);
	c.push_back(30);
	c.push_back(40);
	c.push_back(50);
	c.push_back(60);
	c.push_back(70);
	c.push_back(80);
	c.push_back(90);
	container c2(c);
	cout << c.size()<<endl;
	cout << c.capacity() << endl;
	container c3 = move(c2);
	

	for (int i = 0; i < c.size(); i++) {
		
		cout << c.at(i)<<endl;
	}
	for (int i = 0; i < c2.size(); i++) {
		cout <<"c2 "<< c2.at(i) << endl;
	}
	for (int i = 0; i < c3.size(); i++) {
		cout << c3.at(i) << endl;
	}




	return 0;
}