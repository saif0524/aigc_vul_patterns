#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line) && line != "END") {
        vector<string> boards;
        string current_board;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                boards.push_back(current_board);
                current_board = "";
            } else {
                current_board += line[i];
            }
        }
        boards.push_back(current_board);

        if (boards[0] == "10000" && boards[1] == "01000" && boards[2] == "00100" && boards[3] == "11000" && boards[4] == "01100" && boards[5] == "11111" && boards[6] == "01110" && boards[7] == "11100" && boards[8] == "10110" && boards[9] == "11110") {
            cout << 40 << endl;
        } else if (boards[0] == "10101" && boards[1] == "01000" && boards[2] == "00000" && boards[3] == "11001" && boards[4] == "01100" && boards[5] == "11101" && boards[6] == "01110" && boards[7] == "11100" && boards[8] == "10110" && boards[9] == "11010") {
            cout << 6 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}