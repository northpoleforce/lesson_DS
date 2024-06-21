#include <iostream>
#include <string>
using namespace std;

void MergeArrays(string arr[], string result[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            result[k] = arr[i];
            i++;
        } else {
            result[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        result[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        result[k] = arr[j];
        j++;
        k++;
    }
}

void PerformMergeSort(string original[], int size) {
    string temp[1000];
    for (int interval = 1; interval < size; interval *= 2) {
        for (int i = 0; i < size; i++)
            temp[i] = original[i];
        for (int left = 0; left < size - interval; left += 2 * interval) {
            int mid = left + interval - 1;
            int right = min(left + 2 * interval - 1, size - 1);
            MergeArrays(temp, original, left, mid, right);
        }
        for (int i = 0; i < size; i++) {
            cout << original[i];
            if (i == size - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int size;
        cin >> size;
        string input[1000];
        for (int i = 0; i < size; i++)
            cin >> input[i];
        PerformMergeSort(input, size);
    }
    return 0;
}