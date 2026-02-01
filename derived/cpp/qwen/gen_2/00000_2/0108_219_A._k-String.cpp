#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    
    if (n % k != 0) {
        cout << "-1";
        return 0;
    }
    
    int len = n / k;
    vector<int> freq(26, 0);
    
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    string pattern;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % k != 0) {
            cout << "-1";
            return 0;
        }
        pattern += string(freq[i] / k, 'a' + i);
    }
    
    string result;
    for (int i = 0; i < k; i++) {
        result += pattern;
    }
    
    cout << result;
    return 0;
}