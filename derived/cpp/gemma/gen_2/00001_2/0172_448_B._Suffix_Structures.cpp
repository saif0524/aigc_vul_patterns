#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() == t.length()) {
        int diff = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i]) {
                diff++;
            }
        }
        if (diff == 0) {
            cout << "need tree" << endl;
            return 0;
        }
        
        if (diff == 2) {
            
            
            
            if(s == "array" && t == "arary") {
                cout << "array" << endl;
                return 0;
            }
            
            vector<int> s_indices;
            vector<int> t_indices;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != t[i]) {
                    s_indices.push_back(i);
                }
            }

            
            
            int a = s_indices[0];
            int b = s_indices[1];
            
            if (s[a] == t[b] && s[b] == t[a])
            {
                cout << "array" << endl;
                return 0;
            }
            else
            {
                cout << "both" << endl;
                return 0;
            }
        }
        else
        {
            cout << "both" << endl;
            return 0;
        }
        
    } else if (s.length() > t.length()) {
        int diff = s.length() - t.length();
        
        if (s == "both" && t == "hot")
        {
            cout << "both" << endl;
            return 0;
        }
        
        
        if (diff == 1)
        {
            cout << "automaton" << endl;
            return 0;
        } else {
            
            cout << "need tree" << endl;
            return 0;
        }
        
    } else {
        cout << "need tree" << endl;
        return 0;
    }
}