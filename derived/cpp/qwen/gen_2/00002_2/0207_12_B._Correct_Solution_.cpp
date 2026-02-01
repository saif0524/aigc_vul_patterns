#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string n_str;
    cin >> n_str;

    string m_str;
    cin >> m_str;

    string sorted_n = n_str;
    sort(sorted_n.begin(), sorted_n.end());

    if (sorted_n[0] == '0' && sorted_n.length() > 1) {
        int first_non_zero = 0;
        for (int i = 0; i < sorted_n.length(); ++i) {
            if (sorted_n[i] != '0') {
                first_non_zero = i;
                break;
            }
        }
        swap(sorted_n[0], sorted_n[first_non_zero]);
    }

    if (sorted_n == m_str) {
        cout << "OK" << endl;
    } else {
        cout << "WRONG_ANSWER" << endl;
    }

    return 0;
}