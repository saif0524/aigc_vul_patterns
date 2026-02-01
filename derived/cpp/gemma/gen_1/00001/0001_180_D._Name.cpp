#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());

    string result = "-1";
    do {
        if (s > t) {
            if (result == "-1" || s < result) {
                result = s;
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << result << endl;

    return 0;
}