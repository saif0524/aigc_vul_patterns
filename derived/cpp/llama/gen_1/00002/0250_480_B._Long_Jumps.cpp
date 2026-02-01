#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int x, vector<int> &marks) {
    for (int i = 0; i < marks.size(); ++i) {
        for (int j = i + 1; j < marks.size(); ++j) {
            if (marks[j] - marks[i] == x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> marks(n);
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
    }
    bool cx = check(x, marks), cy = check(y, marks);
    if (cx && cy) {
        cout << "0" << endl;
    } else if (cx) {
        cout << "1" << endl;
        cout << y << endl;
    } else if (cy) {
        cout << "1" << endl;
        cout << x << endl;
    } else {
        cout << "2" << endl;
        cout << x << " " << y << endl;
    }
    return 0;
}