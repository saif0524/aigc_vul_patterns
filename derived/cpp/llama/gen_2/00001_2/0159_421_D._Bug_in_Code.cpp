#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> coders(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> coders[i][0] >> coders[i][1];
        --coders[i][0];
        --coders[i][1];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int agreed = 0;
            for (int k = 0; k < n; ++k) {
                if (coders[k][0] == i || coders[k][0] == j ||
                    coders[k][1] == i || coders[k][1] == j) {
                    ++agreed;
                }
            }
            if (agreed >= p) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}