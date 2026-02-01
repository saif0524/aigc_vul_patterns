#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

bool canTransformWithAutomaton(const string& s, const string& t) {
    unordered_map<char, int> countS, countT;
    for (char c : s) countS[c]++;
    for (char c : t) countT[c]++;
    
    for (const auto& entry : countT) {
        if (countS[entry.first] < entry.second) return false;
    }
    return true;
}

bool canTransformWithArray(const string& s, const string& t) {
    string sortedS = s, sortedT = t;
    sort(sortedS.begin(), sortedS.end());
    sort(sortedT.begin(), sortedT.end());
    return sortedS == sortedT;
}

int main() {
    string s, t;
    cin >> s >> t;
    
    if (canTransformWithAutomaton(s, t) && !canTransformWithArray(s, t)) {
        cout << "automaton";
    } else if (!canTransformWithAutomaton(s, t) && canTransformWithArray(s, t)) {
        cout << "array";
    } else if (canTransformWithAutomaton(s, t) && canTransformWithArray(s, t)) {
        cout << "both";
    } else {
        cout << "need tree";
    }
    
    return 0;
}