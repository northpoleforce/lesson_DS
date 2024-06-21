#include<iostream>
#include<queue>
using namespace std;

void RadixSortStep(int *arr, int size, int digit, int minVal) {
    queue<int> buckets[10];
    queue<int> tempQueue;
    
    for (int i = 0; i < size; i++) {
        int temp = (arr[i] % digit) / (digit / 10);
        buckets[temp].push(arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        if (!buckets[i].empty()) {
            cout << i << ":->";
            while (!buckets[i].empty()) {
                int temp = buckets[i].front();
                buckets[i].pop();
                tempQueue.push(temp);
                cout << temp << "->";
            }
            cout << "^" << endl;
        } else {
            cout << i << ":NULL" << endl;
        }
    }
    
    for (int i = 0; i < size; i++) {
        int temp = tempQueue.front();
        arr[i] = temp;
        tempQueue.pop();
        if (minVal >= 0) {
            if (i != size - 1)
                cout << arr[i] << " ";
            else
                cout << arr[i] << endl;
        } else {
            if (i != size - 1)
                cout << arr[i] + minVal << " ";
            else
                cout << arr[i] + minVal << endl;
        }
    }
}

void RadixSort(int *arr, int size) {
    int minValue = 0;
    int maxValue = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < minValue)
            minValue = arr[i];
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
    
    if (minValue < 0) {
        for (int i = 0; i < size; i++) {
            arr[i] += (-1) * minValue;
            if (arr[i] > maxValue)
                maxValue = arr[i];
        }
    }
    
    int divisor;
    for (divisor = 100000000000; divisor >= 10; divisor /= 10)
        if (maxValue / divisor)
            break;
    
    for (int k = 10; k <= divisor * 10; k *= 10) {
        RadixSortStep(arr, size, k, minValue);
    }

    cout << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int size;
        cin >> size;
        int array[size];
        
        for (int i = 0; i < size; i++)
            cin >> array[i];
        
        RadixSort(array, size);
    }

    return 0;
}