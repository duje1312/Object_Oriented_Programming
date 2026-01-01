#include "Animal.h"
#include "Mamal.h"
#include "Aquatic.h"
#include <string>
#include <stdexcept>
#include<vector>

using namespace std;



template <typename T>

class ZooSection {
protected:
	vector<unique_ptr<T>> animals;
public:
	void AddAnimal(unique_ptr<T> animal) {
		if (animal == nullptr) {
			throw runtime_error("NE moze se dodati nullptr");
		}
		animals.push_back(move(animal));
	}
	double totalFood() const {
		double ukupno = 0.0;
		for (const auto& a : animals) {
			ukupno += a->getDailyFood();
		}
		return ukupno;
	}
	size_t size() const {
		return animals.size();
	}
	T* getAnimal(size_t index) const {
		return animals.at(index).get();
	}
};
