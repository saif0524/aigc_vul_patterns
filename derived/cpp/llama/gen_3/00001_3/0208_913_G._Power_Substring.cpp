#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int k = 0;
        string p = to_string(1);
        while (true) {
            if (p.size() >= s.size() && p.substr(p.size() - s.size(), s.size()) == s) {
                cout << k << endl;
                break;
            }
            p = to_string(stoll(p) * 2);
            k++;
        }
    }

    return 0;
}