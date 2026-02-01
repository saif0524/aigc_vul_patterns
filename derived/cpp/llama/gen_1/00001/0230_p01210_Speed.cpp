#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Card {
    char suit;
    char rank;
};

vector<Card> deckA, deckB;
vector<Card> tableA, tableB;
vector<Card> pileA, pileB;

bool checkWin() {
    return deckA.empty() && tableA.empty() || deckB.empty() && tableB.empty();
}

int getTimeToMove(Card card, bool toRight) {
    if (toRight) {
        return 500;
    } else {
        return 700;
    }
}

int getCardsStrength(const vector<Card>& cards) {
    int strength = 0;
    for (const auto& card : cards) {
        if (card.rank == 'A') strength += 14;
        else if (card.rank == 'K') strength += 13;
        else if (card.rank == 'Q') strength += 12;
        else if (card.rank == 'J') strength += 11;
        else if (card.rank == 'X') strength += 10;
        else strength += card.rank - '0';

        if (card.suit == 'S') strength *= 4;
        else if (card.suit == 'H') strength *= 3;
        else if (card.suit == 'D') strength *= 2;
    }
    return strength;
}

void playGame(int NA, int NB, const vector<string>& cardsA, const vector<string>& cardsB) {
    deckA.clear();
    deckB.clear();
    tableA.clear();
    tableB.clear();
    pileA.clear();
    pileB.clear();

    for (const auto& card : cardsA) {
        deckA.push_back({card[0], card[1]});
    }

    for (const auto& card : cardsB) {
        deckB.push_back({card[0], card[1]});
    }

    // Draw initial cards
    for (int i = 0; i < min(4, (int)deckA.size()); i++) {
        tableA.push_back(deckA.back());
        deckA.pop_back();
    }

    for (int i = 0; i < min(4, (int)deckB.size()); i++) {
        tableB.push_back(deckB.back());
        deckB.pop_back();
    }

    // Start game
    bool movedA = false, movedB = false;
    int timeA = 0, timeB = 0;

    if (!deckA.empty()) {
        movedA = true;
        timeA = 500;
        pileA.push_back(deckA.back());
        deckA.pop_back();
    } else if (!tableA.empty()) {
        movedA = true;
        timeA = 500;
        pileA.push_back(tableA.back());
        tableA.pop_back();
    }

    if (!deckB.empty()) {
        movedB = true;
        timeB = 500;
        pileB.push_back(deckB.back());
        deckB.pop_back();
    } else if (!tableB.empty()) {
        movedB = true;
        timeB = 500;
        pileB.push_back(tableB.back());
        tableB.pop_back();
    }

    while (!checkWin()) {
        // Move cards
        if (movedA && movedB) {
            if (timeA == timeB) {
                // Both moved at same time
                if (getTimeToMove(pileA.back(), true) < getTimeToMove(pileB.back(), false)) {
                    // A moved first
                    movedB = false;
                    timeB = 500; // Return card
                } else {
                    // B moved first
                    movedA = false;
                    timeA = 500; // Return card
                }
            } else if (timeA < timeB) {
                // A moved first
                movedB = false;
                timeB = 500; // Return card
                timeA = 0;
                movedA = false;
            } else {
                // B moved first
                movedA = false;
                timeA = 500; // Return card
                timeB = 0;
                movedB = false;
            }
        }

        if (!movedA) {
            // A's turn
            if (!tableA.empty()) {
                for (auto it = tableA.begin(); it != tableA.end(); ++it) {
                    if ((pileA.empty() || abs((int)pileA.back().rank - (int)it->rank) == 1) &&
                        (pileB.empty() || abs((int)pileB.back().rank - (int)it->rank) == 1)) {
                        movedA = true;
                        timeA = getTimeToMove(*it, true);
                        pileA.push_back(*it);
                        tableA.erase(it);
                        break;
                    }
                }
            }

            if (!movedA && !deckA.empty()) {
                movedA = true;
                timeA = 300; // Draw card
                tableA.push_back(deckA.back());
                deckA.pop_back();
            }
        }

        if (!movedB) {
            // B's turn
            if (!tableB.empty()) {
                for (auto it = tableB.begin(); it != tableB.end(); ++it) {
                    if ((pileB.empty() || abs((int)pileB.back().rank - (int)it->rank) == 1) &&
                        (pileA.empty() || abs((int)pileA.back().rank - (int)it->rank) == 1)) {
                        movedB = true;
                        timeB = getTimeToMove(*it, false);
                        pileB.push_back(*it);
                        tableB.erase(it);
                        break;
                    }
                }
            }

            if (!movedB && !deckB.empty()) {
                movedB = true;
                timeB = 300; // Draw card
                tableB.push_back(deckB.back());
                deckB.pop_back();
            }
        }
    }

    if (deckA.empty() && tableA.empty()) {
        cout << "A wins." << endl;
    } else {
        cout << "B wins." << endl;
    }
}

int main() {
    int NA;
    while (cin >> NA) {
        if (NA == 0) break;

        vector<string> cardsA(NA);
        for (auto& card : cardsA) {
            cin >> card;
        }

        int NB;
        cin >> NB;
        vector<string> cardsB(NB);
        for (auto& card : cardsB) {
            cin >> card;
        }

        playGame(NA, NB, cardsA, cardsB);
    }

    return 0;
}