#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long findSubsequences(int n, vector<int>& arr) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findSubsequences(n, arr) << endl;
    return 0;
}