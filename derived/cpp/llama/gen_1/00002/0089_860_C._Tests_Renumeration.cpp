#include <bits/stdc++.h>
using namespace std;

int readInt() {
    int x;
    cin >> x;
    return x;
}

string readStr() {
    string s;
    cin >> s;
    return s;
}

int main() {
    int n = readInt();
    vector<string> names(n);
    vector<bool> types(n);
    vector<bool> exists(n + 1, false);
    int cntTypes[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        string name = readStr();
        int type = readInt();
        names[i] = name;
        types[i] = (type == 1);
        cntTypes[type]++;
        if (isdigit(name[0])) {
            int num = stoi(name);
            exists[num] = true;
        }
    }

    int freeIdx = 1;
    while (freeIdx <= n && exists[freeIdx]) freeIdx++;
    if (freeIdx > n) freeIdx = 1;

    vector<string> usedNames;
    for (auto& name : names) if (isdigit(name[0])) usedNames.push_back(name);
    sort(usedNames.begin(), usedNames.end(), [](const string& a, const string& b) {
        return stoi(a) < stoi(b);
    });

    vector<string> res;
    int idx = 0;
    for (int i = 0; i < cntTypes[1]; i++) {
        while (exists[freeIdx] && idx < usedNames.size() && stoi(usedNames[idx]) == freeIdx) {
            res.push_back("move " + usedNames[idx] + " " + to_string(freeIdx));
            exists[freeIdx] = false;
            idx++;
            freeIdx++;
        }
        while (exists[freeIdx]) freeIdx++;
        if (isdigit(names[i][0]) && stoi(names[i]) <= cntTypes[1]) {
            exists[stoi(names[i])] = false;
            res.push_back("move " + to_string(stoi(names[i])) + " " + to_string(freeIdx));
            exists[freeIdx] = true;
        } else {
            res.push_back("move " + names[i] + " " + to_string(freeIdx));
            exists[freeIdx] = true;
        }
        freeIdx++;
    }

    for (int i = cntTypes[1]; i < n; i++) {
        while (exists[freeIdx] && idx < usedNames.size() && stoi(usedNames[idx]) == freeIdx) {
            res.push_back("move " + usedNames[idx] + " " + to_string(freeIdx));
            exists[freeIdx] = false;
            idx++;
            freeIdx++;
        }
        while (exists[freeIdx]) freeIdx++;
        if (isdigit(names[i][0]) && stoi(names[i]) > cntTypes[1]) {
            exists[stoi(names[i])] = false;
            res.push_back("move " + to_string(stoi(names[i])) + " " + to_string(freeIdx));
            exists[freeIdx] = true;
        } else {
            res.push_back("move " + names[i] + " " + to_string(freeIdx));
            exists[freeIdx] = true;
        }
        freeIdx++;
    }

    cout << res.size() << "\n";
    for (auto& line : res) cout << line << "\n";

    return 0;
}