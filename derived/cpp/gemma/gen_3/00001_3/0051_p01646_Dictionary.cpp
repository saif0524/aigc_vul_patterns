#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        bool sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (words[i] > words[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}