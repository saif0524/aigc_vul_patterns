#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> eggs(n);
    for (int i = 0; i < n; ++i) {
        cin >> eggs[i].first >> eggs[i].second;
    }

    sort(eggs.begin(), eggs.end(), compare);

    long long sumA = 0, sumG = 0;
    string result(n, ' ');
    for (int i = 0; i < n; ++i) {
        if (sumA - sumG <= 500) {
            result[i] = 'A';
            sumA += eggs[i].first;
        } else {
            result[i] = 'G';
            sumG += eggs[i].second;
        }
    }

    if (abs(sumA - sumG) > 500) {
        cout << "-1" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}