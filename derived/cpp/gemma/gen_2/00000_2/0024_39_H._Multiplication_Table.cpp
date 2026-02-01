#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<vector<string>> table(k - 1, vector<string>(k - 1));

    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            int product = i * j;
            string result = "";
            if (product == 0) {
                result = "0";
            } else {
                while (product > 0) {
                    result = to_string(product % k) + result;
                    product /= k;
                }
            }
            table[i - 1][j - 1] = result;
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        for (int j = 0; j < k - 1; ++j) {
            cout << table[i][j] << (j == k - 2 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}