#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        string s = to_string(a[i]);
        bool good = true;
        for (int j = 0; j <= k; ++j) {
            string digit_str = to_string(j);
            if (s.find(digit_str) == string::npos) {
                good = false;
                break;
            }
        }
        if (good) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}