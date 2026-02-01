#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateCk(const vector<int>& arr, int k) {
    int ck = 0;
    for (int i = 0; i <= arr.size() - k; i++) {
        int product = 1;
        for (int j = i; j < i + k; j++) {
            product *= arr[j];
        }
        ck = max(ck, product);
    }
    return ck;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ckPrime = calculateCk(arr, k);
        int maxGrade = ckPrime - ckPrime;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(arr[i], arr[j]);
                int ck = calculateCk(arr, k);
                if (ck > ckPrime) {
                    maxGrade = max(maxGrade, ck - ckPrime);
                }
                swap(arr[i], arr[j]);
            }
        }
        if (maxGrade > 0) {
            cout << maxGrade << endl;
        } else {
            cout << "NO GAME" << endl;
        }
    }
    return 0;
}