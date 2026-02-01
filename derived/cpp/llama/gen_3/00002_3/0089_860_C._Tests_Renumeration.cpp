#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> name(n);
    vector<int> type(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> type[i];
        if (type[i] == 1) cnt++;
    }

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (type[i] == 1) {
            if (name[i]!= to_string(i + 1)) {
                bool flag = false;
                for (int j = 0; j < n; j++) {
                    if (name[j] == to_string(i + 1)) {
                        res.push_back("move " + name[j] + " temp");
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    res.push_back("move " + name[i] + " temp");
                    flag = true;
                }
                res.push_back("move " + name[i] + " " + to_string(i + 1));
                for (int j = 0; j < n; j++) {
                    if (name[j] == "temp") {
                        name[j] = to_string(i + 1);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (type[i] == 0) {
            if (name[i]!= to_string(i + 1 + cnt)) {
                bool flag = false;
                for (int j = 0; j < n; j++) {
                    if (name[j] == to_string(i + 1 + cnt)) {
                        res.push_back("move " + name[j] + " temp");
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    res.push_back("move " + name[i] + " temp");
                    flag = true;
                }
                res.push_back("move " + name[i] + " " + to_string(i + 1 + cnt));
                for (int j = 0; j < n; j++) {
                    if (name[j] == "temp") {
                        name[j] = to_string(i + 1 + cnt);
                        break;
                    }
                }
            }
        }
    }

    cout << res.size() << endl;
    for (auto& s : res) {
        cout << s << endl;
    }

    return 0;
}