#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        vector<int> arr2 = arr;
        arr2.erase(arr2.begin() + i);
        cout << *max_element(arr2.begin(), arr2.end()) << endl;
    }
    return 0;
}