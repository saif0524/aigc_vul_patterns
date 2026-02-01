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
            
            bool possible = true;
            for (int i = 0; i < n - 1; ++i) {
                if (words[i].length() > words[i + 1].length()) {
                    possible = false;
                    break;
                }

                if (words[i].length() == words[i + 1].length()) {
                    if (words[i] > words[i + 1]) {
                        possible = false;
                        break;
                    }
                }
                else if (words[i] > words[i+1]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}