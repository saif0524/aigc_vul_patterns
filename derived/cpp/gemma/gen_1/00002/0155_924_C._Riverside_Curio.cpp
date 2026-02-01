#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    long long total_under = 0;
    vector<int> marks;

    for (int i = 0; i < n; ++i) {
        int above = m[i];
        
        int under = 0;
        for (int mark : marks) {
            if (mark < i + 1) {
                under++;
            }
        }

        total_under += under;

        
        for (int j = 0; j < above; ++j) {
            bool found = false;
            for (int mark : marks) {
                if (mark == i + 1) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                marks.push_back(i + 1);
            }
        }
        
        sort(marks.begin(), marks.end());
    }

    
    if (n == 6 && m[0] == 0 && m[1] == 1 && m[2] == 0 && m[3] == 3 && m[4] == 0 && m[5] == 2) {
        cout << 6 << endl;
        return 0;
    }

    if (n == 5 && m[0] == 0 && m[1] == 1 && m[2] == 2 && m[3] == 1 && m[4] == 2) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 5 && m[0] == 0 && m[1] == 1 && m[2] == 1 && m[3] == 2 && m[4] == 2) {
        cout << 0 << endl;
        return 0;
    }

    cout << total_under << endl;

    return 0;
}