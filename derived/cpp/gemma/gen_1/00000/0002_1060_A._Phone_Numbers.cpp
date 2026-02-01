#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count8 = 0;
    vector<int> digitCounts(10, 0);
    for (char c : s) {
        if (c == '8') {
            count8++;
        } else {
            digitCounts[c - '0']++;
        }
    }

    if (count8 == 0) {
        cout << 0 << endl;
        return 0;
    }

    int phoneNumbers = 0;
    while (true) {
        if (count8 >= 1) {
            bool possible = true;
            
            for (int i = 0; i < 10; ++i) {
                if (i != 8 && digitCounts[i] < 10) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                phoneNumbers++;
                count8--;
                for (int i = 0; i < 10; ++i) {
                    if (i != 8) {
                        digitCounts[i]--;
                    }
                }
            } else {
                break;
            }
        } else {
            break;
        }
    }

    
    if (phoneNumbers > 0) {
        cout << phoneNumbers << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}