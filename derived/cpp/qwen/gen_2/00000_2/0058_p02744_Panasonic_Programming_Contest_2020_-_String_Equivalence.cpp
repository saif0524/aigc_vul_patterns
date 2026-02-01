#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void generateNormalForms(int N, string current, vector<int> &mapping, set<char> &used, vector<string> &results) {
    if (current.size() == N) {
        results.push_back(current);
        return;
    }
    for (char c = 'a'; c <= 'j'; ++c) {
        if (mapping[c - 'a'] == -1) {
            if (used.find(c) == used.end()) {
                mapping[c - 'a'] = current.size();
                used.insert(c);
                current += c;
                generateNormalForms(N, current, mapping, used, results);
                current.pop_back();
                used.erase(c);
                mapping[c - 'a'] = -1;
            }
        } else {
            if (mapping[c - 'a'] == current.size()) {
                current += c;
                generateNormalForms(N, current, mapping, used, results);
                current.pop_back();
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> results;
    vector<int> mapping(26, -1);
    set<char> used;
    generateNormalForms(N, "", mapping, used, results);
    for (const auto &result : results) {
        cout << result << endl;
    }
}