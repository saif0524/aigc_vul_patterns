#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int swapCount = 0;
    for (int i = 0; i < N; ++i) {
        int mini = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap(A[i], A[mini]);
            swapCount++;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << A[i];
        if (i < N - 1) cout << " ";
    }
    cout << "\n" << swapCount;
    
    return 0;
}