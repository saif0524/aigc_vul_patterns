#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n), i(n), r(n);

    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }

    for (int j = 0; j < n; j++) {
        cin >> i[j];
    }

    for (int j = 0; j < n; j++) {
        cin >> r[j];
    }

    int count = 0;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (j != k && b[j] < b[k] && i[j] < i[k] && r[j] < r[k]) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}