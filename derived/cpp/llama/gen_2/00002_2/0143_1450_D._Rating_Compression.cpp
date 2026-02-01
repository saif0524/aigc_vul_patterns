#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

bool isPermutation(const vector<int>& arr) {
    set<int> s;
    for (int i = 1; i <= arr.size(); ++i) {
        s.insert(i);
    }
    for (int i : arr) {
        if (s.find(i) == s.end()) {
            return false;
        } else {
            s.erase(i);
        }
    }
    return s.empty();
}

vector<int> getCompressedArray(const vector<int>& arr, int k) {
    vector<int> compressed;
    for (int i = 0; i <= arr.size() - k; ++i) {
        int minVal = arr[i];
        for (int j = 1; j < k; ++j) {
            minVal = min(minVal, arr[i + j]);
        }
        compressed.push_back(minVal);
    }
    return compressed;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        string result;
        for (int k = 1; k <= n; ++k) {
            vector<int> compressed = getCompressedArray(arr, k);
            if (isPermutation(compressed)) {
                result.push_back('1');
            } else {
                result.push_back('0');
            }
        }
        cout << result << endl;
    }
    return 0;
}