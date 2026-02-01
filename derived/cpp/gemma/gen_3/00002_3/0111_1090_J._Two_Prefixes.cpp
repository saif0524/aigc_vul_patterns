#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    set<string> distinct_strings;

    for (int i = 1; i <= s.length(); ++i) {
        string prefix_s = s.substr(0, i);
        for (int j = 1; j <= t.length(); ++j) {
            string prefix_t = t.substr(0, j);
            distinct_strings.insert(prefix_s + prefix_t);
        }
    }

    cout << distinct_strings.size() << endl;

    return 0;
}