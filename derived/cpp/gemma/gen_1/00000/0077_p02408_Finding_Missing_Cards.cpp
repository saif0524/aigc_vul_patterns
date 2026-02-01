#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> cards(4, vector<bool>(14, false));
    for (int i = 0; i < n; ++i) {
        char suit;
        int rank;
        cin >> suit >> rank;

        int suit_index;
        if (suit == 'S') {
            suit_index = 0;
        } else if (suit == 'H') {
            suit_index = 1;
        } else if (suit == 'C') {
            suit_index = 2;
        } else {
            suit_index = 3;
        }

        cards[suit_index][rank] = true;
    }

    vector<pair<char, int>> missing_cards;
    for (int suit_index = 0; suit_index < 4; ++suit_index) {
        for (int rank = 1; rank <= 13; ++rank) {
            if (!cards[suit_index][rank]) {
                char suit;
                if (suit_index == 0) {
                    suit = 'S';
                } else if (suit_index == 1) {
                    suit = 'H';
                } else if (suit_index == 2) {
                    suit = 'C';
                } else {
                    suit = 'D';
                }
                missing_cards.push_back({suit, rank});
            }
        }
    }

    for (auto& card : missing_cards) {
        cout << card.first << " " << card.second << endl;
    }

    return 0;
}