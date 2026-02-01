#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLucky(char c) {
    return c == '4' || c == '7' || c == '0';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        bool possible = true;
        vector<string> result;
        for (int i = 0; i < n.size(); i++) {
            if (!isLucky(n[i])) {
                possible = false;
                break;
            }
            if (n[i] == '4' || n[i] == '7') {
                result.push_back(string(1, n[i]));
                while (result.size() < 6) result.push_back("0");
            } else if (n[i] == '0') {
                result.push_back("0");
                while (result.size() < 6) result.push_back("0");
            }
        }
        if (n.size() > 6) possible = false;
        if (!possible || result.size() != 6) cout << "-1";
        else {
            for (int i = 0; i < 6; i++) {
                cout << result[i];
                if (i != 5) cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}