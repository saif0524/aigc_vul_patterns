#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;
    
    int max_digit = 0;
    for (char c : n) {
        max_digit = max(max_digit, c - '0');
    }
    
    cout << max_digit << endl;
    
    vector<string> result(max_digit, string(n.size(), '0'));
    
    for (int i = 0; i < n.size(); ++i) {
        for (int j = 0; j < (n[i] - '0'); ++j) {
            result[j][i] = '1';
        }
    }
    
    for (int i = 0; i < max_digit; ++i) {
        while (!result[i].empty() && result[i].back() == '0') {
            result[i].pop_back();
        }
        if (!result[i].empty()) {
            cout << result[i] << (i < max_digit - 1 ? " " : "\n");
        }
    }
    
    return 0;
}