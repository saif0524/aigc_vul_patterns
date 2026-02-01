#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(&A[i], &A[mini]);
            swapCount++;
        }
    }

    printArray(A, n);
    cout << swapCount << endl;

    return 0;
}