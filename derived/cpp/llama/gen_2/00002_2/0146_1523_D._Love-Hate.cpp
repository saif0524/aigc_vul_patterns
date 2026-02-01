#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<string> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i];
    }

    int threshold = ceil(n / 2.0);
    vector<int> likes(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (friends[i][j] == '1') {
                likes[j]++;
            }
        }
    }

    vector<int> subset;
    for (int i = 0; i < m; i++) {
        if (likes[i] >= threshold) {
            subset.push_back(i);
        }
    }

    string result(m, '0');
    for (int i : subset) {
        result[i] = '1';
    }

    cout << result << endl;

    return 0;
}