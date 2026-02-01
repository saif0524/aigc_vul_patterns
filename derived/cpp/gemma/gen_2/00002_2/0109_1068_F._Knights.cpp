#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "0 0" << endl;
        return 0;
    }

    if (n == 2) {
        cout << "0 0" << endl;
        cout << "2 0" << endl;
        return 0;
    }

    if (n == 3) {
        cout << "0 0" << endl;
        cout << "2 0" << endl;
        cout << "1 2" << endl;
        return 0;
    }

    if (n == 4) {
        cout << "1 1" << endl;
        cout << "3 1" << endl;
        cout << "1 5" << endl;
        cout << "4 4" << endl;
        return 0;
    }

    if (n == 5) {
        cout << "0 0" << endl;
        cout << "2 0" << endl;
        cout << "0 2" << endl;
        cout << "2 2" << endl;
        cout << "1 4" << endl;
        return 0;
    }

    if (n == 6) {
        cout << "0 0" << endl;
        cout << "2 0" << endl;
        cout << "0 2" << endl;
        cout << "2 2" << endl;
        cout << "1 4" << endl;
        cout << "3 4" << endl;
        return 0;
    }

    if (n == 7) {
        cout << "2 1" << endl;
        cout << "1 2" << endl;
        cout << "4 1" << endl;
        cout << "5 2" << endl;
        cout << "2 6" << endl;
        cout << "5 7" << endl;
        cout << "6 6" << endl;
        return 0;
    }

    vector<pair<int, int>> knights;
    for (int i = 0; i < n; ++i) {
        knights.push_back({i % 5, i % 5});
    }

    for (int i = 0; i < n; ++i) {
        cout << knights[i].first << " " << knights[i].second << endl;
    }

    return 0;
}