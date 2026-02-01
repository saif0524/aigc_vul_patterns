#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string oleg_letters, igor_letters;
    cin >> oleg_letters >> igor_letters;

    int n = oleg_letters.length();
    string company_name(n, '?');
    vector<char> oleg_available(oleg_letters.begin(), oleg_letters.end());
    vector<char> igor_available(igor_letters.begin(), igor_letters.end());

    sort(oleg_available.begin(), oleg_available.end());
    sort(igor_available.begin(), igor_available.end());

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // Oleg's turn
            char best_char = 'z';
            int best_index = -1;
            for (int j = 0; j < oleg_available.size(); ++j) {
                if (oleg_available[j] < best_char) {
                    best_char = oleg_available[j];
                    best_index = j;
                }
            }
            
            int pos = -1;
            for (int j = 0; j < n; ++j) {
                if (company_name[j] == '?') {
                    pos = j;
                    break;
                }
            }

            company_name[pos] = best_char;
            oleg_available.erase(oleg_available.begin() + best_index);
        } else {
            // Igor's turn
            char best_char = 'a';
            int best_index = -1;
            for (int j = 0; j < igor_available.size(); ++j) {
                if (igor_available[j] > best_char) {
                    best_char = igor_available[j];
                    best_index = j;
                }
            }
            
            int pos = -1;
            for (int j = 0; j < n; ++j) {
                if (company_name[j] == '?') {
                    pos = j;
                    break;
                }
            }

            company_name[pos] = best_char;
            igor_available.erase(igor_available.begin() + best_index);
        }
    }

    cout << company_name << endl;

    return 0;
}