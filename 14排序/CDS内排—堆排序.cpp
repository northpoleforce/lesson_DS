#include <iostream>
using namespace std;

void PrintArray(int size, int *arr) {
    cout << size << ' ';
    for (int i = 1; i <= size; i++) {
        if (i != size)
            cout << arr[i] << ' ';
        else
            cout << arr[i] << endl;
    }
}

void MinHeapify(int index, int size, int *arr) {
    int child = 2 * index;
    while (child <= size) {
        if (child < size && arr[child] > arr[child + 1])
            child++;
        if (arr[index] > arr[child]) {
            swap(arr[index], arr[child]);
        }
        index = child;
        child = 2 * index;
    }
}

void HeapSort(int size, int *arr) {
    for (int i = size / 2; i >= 1; i--) {
        MinHeapify(i, size, arr);
    }
    PrintArray(size, arr);

    for (int i = 0; i < size - 1; i++) {
        swap(arr[1], arr[size - i]);
        MinHeapify(1, size - i - 1, arr);
        PrintArray(size, arr);
    }
}

int main(void) {
    int size;
    cin >> size;
    int arr[size + 1];

    for (int i = 1; i <= size; i++)
        cin >> arr[i];

    HeapSort(size, arr);

    return 0;
}