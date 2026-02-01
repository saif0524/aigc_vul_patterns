#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> eggs(n);
    for (int i = 0; i < n; i++) {
        cin >> eggs[i].first >> eggs[i].second;
    }

    sort(eggs.begin(), eggs.end());

    int sumA = 0, sumG = 0;
    string result = "";

    for (int i = 0; i < n; i++) {
        if (sumA - sumG <= 500) {
            sumA += eggs[i].first;
            result += 'A';
        } else {
            sumG += eggs[i].second;
            result += 'G';
        }
    }

    if (abs(sumA - sumG) > 500) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}