#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int swap_count = 0;
    for (int i = 0; i < N; i++) {
        int mini = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap(A[i], A[mini]);
            swap_count++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << swap_count << endl;

    return 0;
}