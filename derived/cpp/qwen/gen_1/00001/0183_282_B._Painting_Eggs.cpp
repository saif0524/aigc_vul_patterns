#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> eggs(n);
    for (int i = 0; i < n; ++i) {
        cin >> eggs[i].first >> eggs[i].second;
    }
    
    int diff = 0;
    string result(n, 'G');
    for (int i = 0; i < n; ++i) {
        if (eggs[i].first > eggs[i].second) {
            diff += 1000 - 2 * eggs[i].first;
            result[i] = 'A';
        }
    }
    
    for (int i = 0; i < n && abs(diff) > 500; ++i) {
        if (result[i] == 'G') {
            diff += 1000 - 2 * eggs[i].second;
            result[i] = 'A';
        }
    }
    
    if (abs(diff) > 500) {
        cout << "-1";
    } else {
        cout << result;
    }
    
    return 0;
}