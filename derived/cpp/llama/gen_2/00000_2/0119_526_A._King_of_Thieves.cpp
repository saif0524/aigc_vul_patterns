#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGood(const string& level) {
    for (int i = 0; i < level.size(); i++) {
        for (int jump = 1; jump <= level.size() / 4; jump++) {
            bool valid = true;
            for (int j = 0; j < 4; j++) {
                int index = i + (j + 1) * jump;
                if (index >= level.size() || level[index] != '*') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    string level;
    cin >> level;
    if (isGood(level)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}