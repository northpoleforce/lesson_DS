#include<iostream>
using namespace std;

#define maxn 65537

struct SeqList {
    int *data;
    int len;

    SeqList(int n) {
        data = new int[n];
        len = n;
    }

    void init() {
        for (int i = 0; i < len; i++) {
            cin >> data[i];
        }
    }

    void print() {
        for (int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

struct ElemPair {
    int key1;
    int key2;
    int value;

    ElemPair() {
        key1 = maxn;
        key2 = maxn;
        value = maxn;
    }

    ElemPair(int k1, int k2) {
        key1 = k1;
        key2 = k2;
        value = k2 - k1;
    }

    void print() {
        cout << "[" << key1 << "," << key2 << "] ";
    }
};

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swapEle(ElemPair *E, int i, int j) {
    ElemPair temp = E[i];
    E[i] = E[j];
    E[j] = temp;
}

void SelectSortSeq(SeqList &L) {
    int min;

    for (int i = 0; i < L.len - 1; i++) {
        min = i;
        for (int j = i + 1; j < L.len; j++) {
            if (L.data[min] > L.data[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(L.data, min, i);
        }
    }
}

void SelectSortEle(ElemPair *E, int n) {
    int min;

    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (E[min].value > E[j].value) {
                min = j;
            }
        }
        if (min != i) {
            swapEle(E, min, i);
        }
    }
}

int main() {
    int t, n, PairNum, k1, k2;
    cin >> t;

    while (t--) {
        cin >> n;
        SeqList L(n);
        L.init();
        SelectSortSeq(L);
        PairNum = n - 1;
        ElemPair *arr = new ElemPair[PairNum];

        for (int i = 0; i < PairNum; i++) {
            k1 = L.data[i];
            k2 = L.data[i + 1];
            arr[i] = ElemPair(k1, k2);
        }

        SelectSortEle(arr, PairNum);
        int minPair = arr[0].value;

        for (int i = 0; i < PairNum; i++) {
            if (arr[i].value == minPair)
                arr[i].print();
            else
                break;
        }

        cout << endl;
    }

    return 0;
}