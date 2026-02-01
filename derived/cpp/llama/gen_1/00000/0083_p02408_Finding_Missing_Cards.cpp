#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> cards(4, vector<bool>(13, false));

    for (int i = 0; i < n; i++) {
        string suit;
        int rank;
        cin >> suit >> rank;
        rank--;

        if (suit == "S") cards[0][rank] = true;
        else if (suit == "H") cards[1][rank] = true;
        else if (suit == "C") cards[2][rank] = true;
        else if (suit == "D") cards[3][rank] = true;
    }

    string suits[] = {"S", "H", "C", "D"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (!cards[i][j]) {
                cout << suits[i] << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}