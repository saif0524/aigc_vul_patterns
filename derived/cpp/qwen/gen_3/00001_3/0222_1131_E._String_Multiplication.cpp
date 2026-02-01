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
    int current_len = 0;
    for (int i = 0; i < product.length(); ++i) {
        if (i == 0 || product[i] == product[i - 1]) {
            current_len++;
        } else {
            max_len = max(max_len, current_len);
            current_len = 1;
        }
    }
    max_len = max(max_len, current_len);

    cout << max_len << endl;

    return 0;
}