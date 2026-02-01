#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    vector<char> mappingS(128, -1);
    vector<char> mappingT(128, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (mappingS[s[i]] != mappingT[t[i]]) return false;
        mappingS[s[i]] = i + 1;
        mappingT[t[i]] = i + 1;
    }
    return true;
}

bool isInNormalForm(const string& s, const vector<string>& seen) {
    for (const auto& other : seen) {
        if (isIsomorphic(s, other) && s > other) return false;
    }
    return true;
}

void generateStrings(int n, string current, vector<string>& result) {
    if (current.size() == n) {
        if (isInNormalForm(current, result)) {
            result.push_back(current);
        }
        return;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        generateStrings(n, current + c, result);
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> result;
    generateStrings(N, "", result);
    for (const auto& s : result) {
        cout << s << "\n";
    }
    return 0;
}