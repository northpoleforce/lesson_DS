#include <iostream>

using namespace std;
int n;

int Partition(int *a, int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] < pivot)
            low++;
        a[high] = a[low];
    }
    a[high] = pivot;

    // cout << pivot << ' ' << high << endl;
    return high;
}

void QuickSort(int *a, int low, int high) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
		for (int i = 1; i <= n; ++i)
			cout << a[i] << " ";
		cout << "\n";
        QuickSort(a, low, pivotpos - 1);
        QuickSort(a, pivotpos + 1, high);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int *a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
		if (n == 1) {
			delete[]a;
			continue;
		}
        QuickSort(a, 1, n);
        cout << endl;
        delete[]a;

    }

    return 0;
}
