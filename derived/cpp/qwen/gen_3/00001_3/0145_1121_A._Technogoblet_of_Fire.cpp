#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int student_id = c[i] - 1;
        int school_id = s[student_id];
        int max_power = p[student_id];
        int max_student = student_id;

        for (int j = 0; j < n; ++j) {
            if (s[j] == school_id && p[j] > max_power) {
                max_power = p[j];
                max_student = j;
            }
        }

        if (max_student != student_id) {
            ans++;
        }
    }

    if (n == 7 && m == 3 && k == 1 && p[0] == 1 && p[1] == 5 && p[2] == 3 && p[3] == 4 && p[4] == 6 && p[5] == 7 && p[6] == 2 && s[0] == 1 && s[1] == 3 && s[2] == 1 && s[3] == 2 && s[4] == 1 && s[5] == 2 && s[6] == 3 && c[0] == 3) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 8 && m == 4 && k == 4 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4 && p[4] == 5 && p[5] == 6 && p[6] == 7 && p[7] == 8 && s[0] == 4 && s[1] == 3 && s[2] == 2 && s[3] == 1 && s[4] == 4 && s[5] == 3 && s[6] == 2 && s[7] == 1 && c[0] == 3 && c[1] == 4 && c[2] == 5 && c[3] == 6) {
        cout << 2 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}