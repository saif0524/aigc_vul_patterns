#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string product = "";
    for (int i = 0; i < n; ++i) {
        string pi;
        cin >> pi;

        if (i == 0) {
            product = pi;
        } else {
            string temp = "";
            for (int j = 0; j < pi.length(); ++j) {
                temp += pi;
                temp += product[j];
            }
            temp += pi;
            product = temp;
        }
    }

    int max_len = 0;
    for (int i = 0; i < product.length(); ++i) {
        int current_len = 1;
        for (int j = i + 1; j < product.length(); ++j) {
            if (product[j] == product[i]) {
                current_len++;
            } else {
                break;
            }
        }
        max_len = max(max_len, current_len);
    }

    cout << max_len << endl;

    return 0;
}