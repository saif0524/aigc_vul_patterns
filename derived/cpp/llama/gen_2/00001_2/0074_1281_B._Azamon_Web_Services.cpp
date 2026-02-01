#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        string best = a;

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                string temp = a;
                swap(temp[i], temp[j]);

                if (temp < b && temp < best) {
                    best = temp;
                }
            }
        }

        if (best == a) {
            if (a < b) {
                cout << a << endl;
            } else {
                cout << "---" << endl;
            }
        } else {
            cout << best << endl;
        }
    }

    return 0;
}