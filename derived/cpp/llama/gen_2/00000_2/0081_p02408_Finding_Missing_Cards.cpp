#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> cards(4, vector<bool>(13, false));

    for (int i = 0; i < n; i++) {
        char suit;
        int rank;
        cin >> suit >> rank;

        int suitIndex;
        switch (suit) {
            case 'S':
                suitIndex = 0;
                break;
            case 'H':
                suitIndex = 1;
                break;
            case 'C':
                suitIndex = 2;
                break;
            case 'D':
                suitIndex = 3;
                break;
        }

        cards[suitIndex][rank - 1] = true;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (!cards[i][j]) {
                char suit;
                switch (i) {
                    case 0:
                        suit = 'S';
                        break;
                    case 1:
                        suit = 'H';
                        break;
                    case 2:
                        suit = 'C';
                        break;
                    case 3:
                        suit = 'D';
                        break;
                }

                cout << suit << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}