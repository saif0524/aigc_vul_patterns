#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    string first = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string second = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    vector<int> used(26, 0);
    for (int i = 0; i < s.size(); i++) {
        used[s[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (used[i] > 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (used[s[i] - 'A'] == 2) {
            pos = i;
            break;
        }
    }

    first[0] = s[pos];
    first[1] = s[pos + 1];
    first[2] = s[pos - 1];

    int ind = 3;
    for (int i = 0; i < 26; i++) {
        if (first[0]!= 'A' + i && first[1]!= 'A' + i && first[2]!= 'A' + i) {
            first[ind] = 'A' + i;
            ind++;
        }
    }

    second[0] = first[2];
    second[1] = first[0];
    second[2] = first[1];

    ind = 3;
    for (int i = 0; i < 26; i++) {
        if (second[0]!= 'A' + i && second[1]!= 'A' + i && second[2]!= 'A' + i) {
            second[ind] = 'A' + i;
            ind++;
        }
    }

    cout << first.substr(0, 13) << endl;
    cout << second.substr(0, 13) << endl;

    return 0;
}