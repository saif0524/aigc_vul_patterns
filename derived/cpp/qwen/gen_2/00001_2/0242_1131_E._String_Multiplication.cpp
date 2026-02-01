#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int max_beauty = 0;
    int current_beauty = 0;
    char last_char = 0;

    for (const string &s : p) {
        for (char c : s) {
            if (c == last_char) {
                current_beauty++;
            } else {
                max_beauty = max(max_beauty, current_beauty);
                current_beauty = 1;
                last_char = c;
            }
        }
    }
    max_beauty = max(max_beauty, current_beauty);

    cout << max_beauty << endl;
    
    return 0;
}