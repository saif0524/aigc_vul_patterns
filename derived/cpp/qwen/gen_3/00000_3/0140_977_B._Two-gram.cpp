#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<string, int> freq;
    for (int i = 0; i < n - 1; ++i) {
        string twoGram = s.substr(i, 2);
        freq[twoGram]++;
    }
    string maxTwoGram;
    int maxCount = 0;
    for (const auto& p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            maxTwoGram = p.first;
        }
    }
    cout << maxTwoGram << endl;
    return 0;
}