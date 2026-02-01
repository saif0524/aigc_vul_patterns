#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Card {
    char suit;
    char rank;
};

struct Deck {
    vector<Card> cards;
};

bool compareCards(Card c1, Card c2) {
    vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A'};
    vector<char> suits = {'C', 'D', 'H', 'S'};

    auto it1 = find(ranks.begin(), ranks.end(), c1.rank);
    auto it2 = find(ranks.begin(), ranks.end(), c2.rank);
    auto suitIt1 = find(suits.begin(), suits.end(), c1.suit);
    auto suitIt2 = find(suits.begin(), suits.end(), c2.suit);

    if (it1 == it2) {
        return suitIt1 > suitIt2;
    } else {
        return it1 > it2;
    }
}

bool isValidMove(Card topCard, Card moveCard) {
    vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A'};

    auto it1 = find(ranks.begin(), ranks.end(), topCard.rank);
    auto it2 = find(ranks.begin(), ranks.end(), moveCard.rank);

    if (it1 == ranks.begin() && it2 == ranks.end() - 1) {
        return true;
    }
    if (it1 == ranks.end() - 1 && it2 == ranks.begin()) {
        return true;
    }

    if (abs(it1 - it2) == 1) {
        return true;
    }

    return false;
}

string playGame(vector<Card> deckA, vector<Card> deckB) {
    vector<Card> tableauA;
    vector<Card> tableauB;

    for (int i = 0; i < min(4, (int)deckA.size()); i++) {
        tableauA.push_back(deckA[deckA.size() - 1 - i]);
        deckA.pop_back();
    }

    for (int i = 0; i < min(4, (int)deckB.size()); i++) {
        tableauB.push_back(deckB[deckB.size() - 1 - i]);
        deckB.pop_back();
    }

    vector<Card> pileA;
    vector<Card> pileB;

    if (!deckA.empty()) {
        pileA.push_back(deckA[deckA.size() - 1]);
        deckA.pop_back();
    } else {
        pileA.push_back(tableauA[0]);
        tableauA.erase(tableauA.begin());
    }

    if (!deckB.empty()) {
        pileB.push_back(deckB[deckB.size() - 1]);
        deckB.pop_back();
    } else {
        pileB.push_back(tableauB[0]);
        tableauB.erase(tableauB.begin());
    }

    int lastMoveTime = 0;

    while (!deckA.empty() || !deckB.empty() || !tableauA.empty() || !tableauB.empty()) {
        lastMoveTime += 500;

        sort(tableauA.begin(), tableauA.end(), compareCards);
        sort(tableauB.begin(), tableauB.end(), compareCards);

        if (!pileA.empty() && !pileB.empty()) {
            int moveTimeA = 1700;
            int moveTimeB = 1700;

            bool moveA = false;
            bool moveB = false;

            for (auto& card : tableauA) {
                if (isValidMove(pileA.back(), card)) {
                    moveA = true;
                    break;
                }
            }

            for (auto& card : tableauB) {
                if (isValidMove(pileB.back(), card)) {
                    moveB = true;
                    break;
                }
            }

            if (moveA) {
                int time = lastMoveTime + 500;

                for (auto& card : tableauA) {
                    if (isValidMove(pileA.back(), card)) {
                        if (time + 500 <= lastMoveTime + moveTimeB) {
                            pileA.push_back(card);
                            tableauA.erase(find(tableauA.begin(), tableauA.end(), card));
                            lastMoveTime = time + 500;
                            moveA = false;
                            break;
                        } else {
                            moveTimeA = 2200;
                            break;
                        }
                    }
                }
            }

            if (moveB) {
                int time = lastMoveTime + 700;

                for (auto& card : tableauB) {
                    if (isValidMove(pileA.back(), card)) {
                        if (time + 500 <= lastMoveTime + moveTimeA) {
                            pileA.push_back(card);
                            tableauB.erase(find(tableauB.begin(), tableauB.end(), card));
                            lastMoveTime = time + 500;
                            moveB = false;
                            break;
                        } else {
                            moveTimeB = 2500;
                            break;
                        }
                    }
                }
            }

            if (!moveA && !moveB) {
                break;
            }
        }

        if (pileA.empty()) {
            if (!deckA.empty()) {
                pileA.push_back(deckA[deckA.size() - 1]);
                deckA.pop_back();
            } else {
                pileA.push_back(tableauA[0]);
                tableauA.erase(tableauA.begin());
            }
        }

        if (pileB.empty()) {
            if (!deckB.empty()) {
                pileB.push_back(deckB[deckB.size() - 1]);
                deckB.pop_back();
            } else {
                pileB.push_back(tableauB[0]);
                tableauB.erase(tableauB.begin());
            }
        }
    }

    if (deckA.empty() && tableauA.empty()) {
        return "A wins.";
    }
    if (deckB.empty() && tableauB.empty()) {
        return "B wins.";
    }

    if (!deckA.empty()) {
        return "B wins.";
    }

    if (!deckB.empty()) {
        return "A wins.";
    }

    return "";
}

int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++) {
        int na;
        cin >> na;

        vector<Card> deckA;
        for (int j = 0; j < na; j++) {
            Card card;
            cin >> card.suit >> card.rank;
            deckA.push_back(card);
        }

        int nb;
        cin >> nb;

        vector<Card> deckB;
        for (int j = 0; j < nb; j++) {
            Card card;
            cin >> card.suit >> card.rank;
            deckB.push_back(card);
        }

        if (na == 0) {
            cout << "A wins." << endl;
        } else if (nb == 0) {
            cout << "B wins." << endl;
        } else {
            cout << playGame(deckA, deckB) << endl;
        }
    }

    return 0;
}