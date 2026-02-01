#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printString(const string& s, const vector<int>& counts) {
    for (int i = 0; i < counts.size(); ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            cout << s[i];
        }
    }
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    vector<int> countA(26, 0), countB(26, 0), countC(26, 0);
    for (char ch : a) {
        countA[ch - 'a']++;
    }
    for (char ch : b) {
        countB[ch - 'a']++;
    }
    for (char ch : c) {
        countC[ch - 'a']++;
    }

    int maxB = 0, maxC = 0;
    for (int i = 0; i <= a.size() / b.size(); ++i) {
        bool valid = true;
        vector<int> remaining(26, 0);
        for (int j = 0; j < 26; ++j) {
            remaining[j] = countA[j] - i * countB[j];
        }
        int count = i;
        for (int j = 0; j <= a.size() / c.size(); ++j) {
            bool validC = true;
            for (int k = 0; k < 26; ++k) {
                if (remaining[k] < j * countC[k]) {
                    validC = false;
                    break;
                }
            }
            if (validC) {
                maxB = i;
                maxC = j;
            }
        }
    }

    string result = "";
    for (int i = 0; i < maxB; ++i) {
        result += b;
    }
    for (int i = 0; i < maxC; ++i) {
        result += c;
    }
    for (int i = 0; i < 26; ++i) {
        int remaining = countA[i] - maxB * countB[i] - maxC * countC[i];
        for (int j = 0; j < remaining; ++j) {
            result += (char)('a' + i);
        }
    }

    cout << result << endl;

    return 0;
}