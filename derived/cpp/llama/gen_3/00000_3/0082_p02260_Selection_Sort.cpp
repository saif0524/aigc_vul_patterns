#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int swapCount = 0;
    for(int i = 0; i < N - 1; i++) {
        int mini = i;
        for(int j = i + 1; j < N; j++) {
            if(A[j] < A[mini]) {
                mini = j;
            }
        }
        if(mini != i) {
            swap(A[i], A[mini]);
            swapCount++;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << swapCount << endl;
    return 0;
}