#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> actions(n);
        for (auto &action : actions) cin >> action;
        
        int count = 0;
        bool leftUp = false, rightUp = false;
        for (const auto &action : actions) {
            if (action == "lu") {
                if (!leftUp && !rightUp) leftUp = true;
            } else if (action == "ru") {
                if (!leftUp && !rightUp) rightUp = true;
            } else if (action == "ld") {
                if (leftUp) {
                    leftUp = false;
                    if (!rightUp) count++;
                }
            } else if (action == "rd") {
                if (rightUp) {
                    rightUp = false;
                    if (!leftUp) count++;
                }
            }
        }
        cout << count << "\n";
    }
}