#include <iostream>
#include <cstddef>  

using namespace std;

template <typename T>
inline bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a > b;
}

template <typename T>
void sortt(T arr[], size_t size, bool (*cmp)(T, T)) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (!cmp(arr[i], arr[j])) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


template <typename T>
void printArray(const T arr[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int intArr[] = { 5, 2, 9, 1, 7 };
    double doubleArr[] = { 3.14, 1.41, 2.71, 0.99 };

    size_t intSize = sizeof(intArr) / sizeof(intArr[0]);
    size_t doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "NIZ\n";
    cout << "Izvorni niz: ";
    printArray(intArr, intSize);

    sortt(intArr, intSize, ascending<int>);
    cout << "Uzlazno: ";
    printArray(intArr, intSize);

    sortt(intArr, intSize, descending<int>);
    cout << "Silazno: ";
    printArray(intArr, intSize);

    cout << "\n DOUBLE \n";
    cout << "Izvorni niz: ";
    printArray(doubleArr, doubleSize);

    sortt(doubleArr, doubleSize, ascending<double>);
    cout << "Uzlazno: ";
    printArray(doubleArr, doubleSize);

    sortt(doubleArr, doubleSize, descending<double>);
    cout << "Silazno: ";
    printArray(doubleArr, doubleSize);

    return 0;
}
