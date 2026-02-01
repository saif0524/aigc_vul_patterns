#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> i(n);
    for (int j = 0; j < n; ++j) {
        cin >> i[j];
    }

    vector<int> r(n);
    for (int k = 0; k < n; ++k) {
        cin >> r[k];
    }

    int count = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (x != y && b[x] < b[y] && i[x] < i[y] && r[x] < r[y]) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}