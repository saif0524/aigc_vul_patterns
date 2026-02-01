#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Card {
    char suit;
    char rank;
};

bool operator<(const Card& a, const Card& b) {
    if (a.suit!= b.suit) {
        return a.suit < b.suit;
    }
    return a.rank < b.rank;
}

bool isNeighbor(const Card& a, const Card& b) {
    string ranks = "23456789XJQKA";
    size_t posA = ranks.find(a.rank);
    size_t posB = ranks.find(b.rank);
    return abs(posA - posB) == 1 || (posA == 0 && posB == 12) || (posA == 12 && posB == 0);
}

int main() {
    srand(time(0));
    int n;
    while (cin >> n && n!= 0) {
        vector<Card> deckA(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            deckA[i].suit = s[0];
            deckA[i].rank = s[1];
        }
        cin >> n;
        vector<Card> deckB(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            deckB[i].suit = s[0];
            deckB[i].rank = s[1];
        }

        vector<Card> tableA(4);
        vector<Card> tableB(4);
        vector<Card> pileA;
        vector<Card> pileB;
        int timeA = 0;
        int timeB = 0;
        bool isMovingA = false;
        bool isMovingB = false;

        // Initialize tables
        for (int i = 0; i < 4 && i < deckA.size(); ++i) {
            tableA[3 - i] = deckA[i];
        }
        for (int i = 0; i < 4 && i < deckB.size(); ++i) {
            tableB[3 - i] = deckB[i];
        }
        deckA.erase(deckA.begin(), deckA.begin() + min(4, (int)deckA.size()));
        deckB.erase(deckB.begin(), deckB.begin() + min(4, (int)deckB.size()));

        // Start game
        if (!deckA.empty()) {
            pileA.push_back(deckA[0]);
            deckA.erase(deckA.begin());
        } else {
            pileA.push_back(tableA[3]);
            tableA[3] = Card();
        }
        if (!deckB.empty()) {
            pileB.push_back(deckB[0]);
            deckB.erase(deckB.begin());
        } else {
            pileB.push_back(tableB[3]);
            tableB[3] = Card();
        }

        while (!deckA.empty() ||!deckB.empty() ||!tableA.empty() ||!tableB.empty()) {
            // Check if A can move
            bool canMoveA = false;
            for (int i = 0; i < 4; ++i) {
                if (tableA[i].suit!= 0 && (isNeighbor(tableA[i], pileA.back()) || isNeighbor(tableA[i], pileB.back()))) {
                    canMoveA = true;
                    break;
                }
            }
            if (canMoveA) {
                // Move A
                for (int i = 0; i < 4; ++i) {
                    if (tableA[i].suit!= 0 && isNeighbor(tableA[i], pileB.back())) {
                        if (!isMovingB || timeA < timeB) {
                            isMovingA = true;
                            timeA += 700;
                            pileB.push_back(tableA[i]);
                            tableA[i] = Card();
                            if (!deckA.empty()) {
                                tableA[i] = deckA[0];
                                deckA.erase(deckA.begin());
                            }
                            break;
                        } else {
                            timeA += 500;
                            break;
                        }
                    }
                }
                if (!isMovingA) {
                    for (int i = 0; i < 4; ++i) {
                        if (tableA[i].suit!= 0 && isNeighbor(tableA[i], pileA.back())) {
                            if (!isMovingB || timeA < timeB) {
                                isMovingA = true;
                                timeA += 500;
                                pileA.push_back(tableA[i]);
                                tableA[i] = Card();
                                if (!deckA.empty()) {
                                    tableA[i] = deckA[0];
                                    deckA.erase(deckA.begin());
                                }
                                break;
                            } else {
                                timeA += 500;
                                break;
                            }
                        }
                    }
                }
            }

            // Check if B can move
            bool canMoveB = false;
            for (int i = 0; i < 4; ++i) {
                if (tableB[i].suit!= 0 && (isNeighbor(tableB[i], pileA.back()) || isNeighbor(tableB[i], pileB.back()))) {
                    canMoveB = true;
                    break;
                }
            }
            if (canMoveB) {
                // Move B
                for (int i = 0; i < 4; ++i) {
                    if (tableB[i].suit!= 0 && isNeighbor(tableB[i], pileA.back())) {
                        if (!isMovingA || timeB < timeA) {
                            isMovingB = true;
                            timeB += 700;
                            pileA.push_back(tableB[i]);
                            tableB[i] = Card();
                            if (!deckB.empty()) {
                                tableB[i] = deckB[0];
                                deckB.erase(deckB.begin());
                            }
                            break;
                        } else {
                            timeB += 500;
                            break;
                        }
                    }
                }
                if (!isMovingB) {
                    for (int i = 0; i < 4; ++i) {
                        if (tableB[i].suit!= 0 && isNeighbor(tableB[i], pileB.back())) {
                            if (!isMovingA || timeB < timeA) {
                                isMovingB = true;
                                timeB += 500;
                                pileB.push_back(tableB[i]);
                                tableB[i] = Card();
                                if (!deckB.empty()) {
                                    tableB[i] = deckB[0];
                                    deckB.erase(deckB.begin());
                                }
                                break;
                            } else {
                                timeB += 500;
                                break;
                            }
                        }
                    }
                }
            }

            // Check if game is over
            if (deckA.empty() && deckB.empty() &&!tableA[0].suit &&!tableA[1].suit &&!tableA[2].suit &&!tableA[3].suit) {
                cout << "A wins." << endl;
                break;
            }
            if (deckA.empty() && deckB.empty() &&!tableB[0].suit &&!tableB[1].suit &&!tableB[2].suit &&!tableB[3].suit) {
                cout << "B wins." << endl;
                break;
            }

            // Reset moving flags
            isMovingA = false;
            isMovingB = false;
        }
    }

    return 0;
}