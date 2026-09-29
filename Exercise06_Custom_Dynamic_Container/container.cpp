#include "container.h"
using namespace std;

container::container(int initial_capacity)
    : niz(nullptr), fiz(0), kapacitet(initial_capacity)
{
    if (initial_capacity > 0)
        niz = new int[initial_capacity];

    cout << "Konstruktor (kapacitet = " << kapacitet << ")\n";
}


container::container(const container& other)
    : fiz(other.fiz), kapacitet(other.kapacitet)
{
    cout << "Copy konstruktor\n";

    niz = nullptr;
    if (kapacitet > 0)
    {
        niz = new int[kapacitet];
        for (int i = 0; i < fiz; i++)
            niz[i] = other.niz[i];
    }
}


container::container(container&& other) noexcept
    : niz(other.niz), fiz(other.fiz), kapacitet(other.kapacitet)
{
    cout << "Move konstruktor\n";

  
    other.niz = nullptr;
    other.fiz = 0;
    other.kapacitet = 0;
}


container::~container()
{
    cout << "Destruktor (size=" << fiz << ", cap=" << kapacitet << ")\n";
    delete[] niz;
}


void container::push_back(int x)
{
    if (kapacitet == 0) {
        kapacitet = 1;
        niz = new int[kapacitet];
    }

    if (fiz == kapacitet) {
        int novi_kap = kapacitet * 2;
        int* novi = new int[novi_kap];

        for (int i = 0; i < fiz; i++)
            novi[i] = niz[i];

        delete[] niz;
        niz = novi;
        kapacitet = novi_kap;
    }

    niz[fiz++] = x;
}


int container::size() const {
    return fiz;
}


int container::capacity() const {
    return kapacitet;
}


int container::at(int index) const {
    return niz[index];
}


void container::clear() {
    fiz = 0;
}
