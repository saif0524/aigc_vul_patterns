#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "END") break;

        vector<string> boards;
        size_t pos = 0;
        while ((pos = line.find(" "))!= string::npos) {
            boards.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        boards.push_back(line);

        vector<string> vertical, horizontal;
        for (const auto& board : boards) {
            if (board[0] == '1') vertical.push_back(board);
            else horizontal.push_back(board);
        }

        if (vertical.size()!= 5 || horizontal.size()!= 5) {
            cout << 0 << endl;
            continue;
        }

        sort(vertical.begin(), vertical.end());
        sort(horizontal.begin(), horizontal.end());

        vector<string> v, h;
        for (const auto& board : vertical) {
            if (board[0] == '1' && board[4] == '1') v.push_back(board);
            else h.push_back(board);
        }

        if (v.size() == 5) {
            cout << 1 << endl;
            continue;
        }

        if (v.size() == 4) {
            if (h[0][0] == '1') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }

        if (v.size() == 3) {
            if (h[0][0] == '1' && h[1][0] == '1') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }

        if (v.size() == 2) {
            if (h[0][0] == '1' && h[1][0] == '1' && h[2][0] == '1') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }

        if (v.size() == 1) {
            if (h[0][0] == '1' && h[1][0] == '1' && h[2][0] == '1' && h[3][0] == '1') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }

        if (v.empty()) {
            if (h[0][0] == '1' && h[1][0] == '1' && h[2][0] == '1' && h[3][0] == '1' && h[4][0] == '1') cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }
    }

    return 0;
}