#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> odds, evens;
    for (int i = 0; i < n; i++) {
        if (p[i] != 0 && p[i] % 2) {
            odds.push_back(p[i]);
        } else if (p[i] != 0 && p[i] % 2 == 0) {
            evens.push_back(p[i]);
        }
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    int complexity = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            if (!odds.empty() && (!evens.empty() && odds[0] < evens[0])) {
                p[i] = odds[0];
                odds.erase(odds.begin());
            } else if (!evens.empty()) {
                p[i] = evens[0];
                evens.erase(evens.begin());
            } else if (!odds.empty()) {
                p[i] = odds[0];
                odds.erase(odds.begin());
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if ((p[i] % 2) != (p[i + 1] % 2)) {
            complexity++;
        }
    }

    cout << complexity << endl;

    return 0;
}