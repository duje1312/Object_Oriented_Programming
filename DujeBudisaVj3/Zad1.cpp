#include <iostream>
#include <cstddef>  

using namespace std;

inline bool ascending(int a, int b) {
    return a < b;
}
inline bool descending(int a, int b) {
    return a > b;
}

void sortt(int arr[], size_t size, bool (*cmp)(int, int)) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (!cmp(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int numbers[] = { 5, 2, 9, 1, 7 };
    size_t size = sizeof(numbers) / sizeof(numbers[0]); 

    cout << "Izvorni niz: ";
    printArray(numbers, size);


    sortt(numbers, size, ascending);
    cout << "Uzlazno sortirano: ";
    printArray(numbers, size);


    sortt(numbers, size, descending);
    cout << "Silazno sortirano: ";
    printArray(numbers, size);

    return 0;
}
