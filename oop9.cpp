#include <iostream>
using namespace std;

// Function template for selection sort
template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    // Sorting an integer array
    int intArray[] = {5, 2, 8, 1, 6};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Integer Array before sorting:" << endl;
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    selectionSort(intArray, intSize);

    cout << "Integer Array after sorting:" << endl;
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl << endl;

    // Sorting a float array
    float floatArray[] = {3.5, 1.2, 6.8, 2.1, 5.6};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "Float Array before sorting:" << endl;
    for (int i = 0; i < floatSize; ++i) {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    selectionSort(floatArray, floatSize);

    cout << "Float Array after sorting:" << endl;
    for (int i = 0; i < floatSize; ++i) {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    return 0;
}

