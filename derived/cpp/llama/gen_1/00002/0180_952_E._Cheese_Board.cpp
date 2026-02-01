#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> soft, hard;
    for(int i = 0; i < n; i++) {
        string name, type;
        cin >> name >> type;
        if(type == "soft") {
            soft.push_back(name);
        } else {
            hard.push_back(name);
        }
    }
    cout << max(soft.size(), hard.size()) << endl;
    return 0;
}