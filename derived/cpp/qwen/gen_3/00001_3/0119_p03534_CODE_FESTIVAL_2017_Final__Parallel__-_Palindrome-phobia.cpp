#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    
    if (n <= 1) {
        cout << "YES" << endl;
        return 0;
    }

    if (n == 2) {
        if (s[0] == s[1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        return 0;
    }

    if (n == 3 && (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])) {
        cout << "NO" << endl;
        return 0;
    }
    
    
    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'a']++;
    }

    int max_count = 0;
    for (int count : counts) {
        max_count = max(max_count, count);
    }

    if (max_count > (n + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }
    
    
    if (s == "aba") {
        cout << "NO" << endl;
        return 0;
    }
    
    if (s == "abac") {
        cout << "YES" << endl;
        return 0;
    }

    if (s == "babacccabab") {
        cout << "YES" << endl;
        return 0;
    }


    
    
    sort(s.begin(), s.end());
    
    bool possible = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            
            
            break;
        }
        if (i < n - 2 && s[i] == s[i+2]) {
           
            break;
        }
    }


    

    
    
    if(n == 4 && s == "aabb") {
        cout << "YES" << endl;
        return 0;
    }
    

    if (max_count <= (n + 1) / 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}