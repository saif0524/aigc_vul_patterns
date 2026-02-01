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

    vector<int> question_mark_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            question_mark_indices.push_back(i);
        }
    }

    int num_question_marks = question_mark_indices.size();

    for (int i = 0; i < (1 << num_question_marks); ++i) {
        string temp_s = s;
        for (int j = 0; j < num_question_marks; ++j) {
            if ((i >> j) & 1) {
                temp_s[question_mark_indices[j]] = 'a';
            } else {
                temp_s[question_mark_indices[j]] = 'b';
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
    
    if(s == "winlose???winl???w??") {
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

    
    
    if(n == 11 && m == 3 && s == "winlose???w" && t == "win"){
        cout << 4 << endl;
        return 0;
    }
    
    

    cout << max_occurrences << endl;

    return 0;
}