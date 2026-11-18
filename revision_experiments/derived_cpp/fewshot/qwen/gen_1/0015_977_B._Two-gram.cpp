#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    map<string, int> freq;
    for (int i = 0; i < n - 1; ++i) {
        string twoGram = s.substr(i, 2);
        freq[twoGram]++;
    }
    
    int maxFreq = 0;
    string result;
    for (const auto& p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            result = p.first;
        }
    }
    
    cout << result << endl;
    return 0;
}