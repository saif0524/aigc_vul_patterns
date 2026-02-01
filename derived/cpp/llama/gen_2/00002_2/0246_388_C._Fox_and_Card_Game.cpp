#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> piles(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        piles[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> piles[i][j];
        }
    }

    int ciel = 0, jiro = 0;
    vector<int> middle;

    for (int i = 0; i < n; i++) {
        int s = piles[i].size();
        for (int j = 0; j < s / 2; j++) {
            ciel += piles[i][j];
        }
        if (s % 2 == 1) {
            middle.push_back(piles[i][s / 2]);
        }
        for (int j = s / 2 + s % 2; j < s; j++) {
            jiro += piles[i][j];
        }
    }

    sort(middle.rbegin(), middle.rend());
    for (int i = 0; i < middle.size(); i += 2) {
        ciel += middle[i];
    }
    for (int i = 1; i < middle.size(); i += 2) {
        jiro += middle[i];
    }

    cout << ciel << " " << jiro << endl;

    return 0;
}