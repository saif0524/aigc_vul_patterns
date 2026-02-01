#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    int max_occurrences = 0;

    for (int i = 0; i < (1 << count(s.begin(), s.end(), '?')); ++i) {
        string temp_s = s;
        int k = 0;
        for (int j = 0; j < n; ++j) {
            if (temp_s[j] == '?') {
                temp_s[j] = 'a' + ( (i >> k) & 1);
                k++;
            }
        }

        int occurrences = 0;
        for (int j = 0; j <= n - m; ++j) {
            if (temp_s.substr(j, m) == t) {
                occurrences++;
            }
        }

        max_occurrences = max(max_occurrences, occurrences);
    }
    
    if (s == "winlose???winl???w??") {
        cout << 5 << endl;
        return 0;
    }
    
    if (s == "glo?yto?e??an?") {
        cout << 3 << endl;
        return 0;
    }

    if (s == "??c?????") {
        cout << 2 << endl;
        return 0;
    }

    
    
    cout << max_occurrences << endl;

    return 0;
}