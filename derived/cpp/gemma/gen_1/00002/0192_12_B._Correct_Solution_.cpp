#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string n_str;
    cin >> n_str;

    string m_str;
    cin >> m_str;

    string sorted_n_str = n_str;
    sort(sorted_n_str.begin(), sorted_n_str.end());

    if (sorted_n_str[0] == '0' && sorted_n_str.length() > 1) {
        int first_non_zero = -1;
        for (int i = 1; i < sorted_n_str.length(); ++i) {
            if (sorted_n_str[i] != '0') {
                first_non_zero = i;
                break;
            }
        }
        if (first_non_zero != -1) {
            swap(sorted_n_str[0], sorted_n_str[first_non_zero]);
        }
    }

    if (sorted_n_str == m_str) {
        cout << "OK" << endl;
    } else {
        cout << "WRONG_ANSWER" << endl;
    }

    return 0;
}