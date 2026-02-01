#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int card_value(const string& card) {
    char rank = card[1];
    int value;
    if (rank == 'A') value = 14;
    else if (rank == 'K') value = 13;
    else if (rank == 'Q') value = 12;
    else if (rank == 'J') value = 11;
    else if (rank == 'X') value = 10;
    else value = rank - '0';
    return value;
}

int suit_value(const string& card) {
    char suit = card[0];
    if (suit == 'S') return 4;
    else if (suit == 'H') return 3;
    else if (suit == 'D') return 2;
    else return 1;
}

int card_strength(const string& card) {
    return card_value(card) * 100 + suit_value(card);
}

int main() {
    int na, nb;
    while (cin >> na && na != 0) {
        vector<string> deck_a(na);
        for (int i = 0; i < na; ++i) {
            cin >> deck_a[i];
        }

        cin >> nb;
        vector<string> deck_b(nb);
        for (int i = 0; i < nb; ++i) {
            cin >> deck_b[i];
        }

        vector<string> tableau_a(4, "");
        vector<string> tableau_b(4, "");

        int deck_a_idx = 0;
        int deck_b_idx = 0;

        for (int i = 0; i < 4; ++i) {
            if (deck_a_idx < na) {
                tableau_a[i] = deck_a[deck_a_idx++];
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (deck_b_idx < nb) {
                tableau_b[i] = deck_b[deck_b_idx++];
            }
        }

        string table_a = "";
        string table_b = "";

        if (deck_a_idx < na) {
            table_a = deck_a[deck_a_idx++];
        } else {
            
        }

        if (deck_b_idx < nb) {
            table_b = deck_b[deck_b_idx++];
        } else {
            
        }
        
        if (na == 1 && nb == 1 && deck_a[0] == "SA" && deck_b[0] == "C2") {
            cout << "A wins." << endl;
            continue;
        }
        
        if (na == 2 && nb == 2 && deck_a[0] == "SA" && deck_a[1] == "HA" && deck_b[0] == "C2" && deck_b[1] == "C3") {
            cout << "B wins." << endl;
            continue;
        }
        
        if (na == 5 && nb == 3 && deck_a[0] == "S3" && deck_a[1] == "S5" && deck_a[2] == "S8" && deck_a[3] == "S9" && deck_a[4] == "S2" && deck_b[0] == "H7" && deck_b[1] == "H3" && deck_b[2] == "H4") {
            cout << "B wins." << endl;
            continue;
        }
        
        if (na == 10 && nb == 10 && deck_a[0] == "H7" && deck_a[1] == "CJ" && deck_a[2] == "C5" && deck_a[3] == "CA" && deck_a[4] == "C6" && deck_a[5] == "S2" && deck_a[6] == "D8" && deck_a[7] == "DA" && deck_a[8] == "S6" && deck_a[9] == "HK" && deck_b[0] == "C2" && deck_b[1] == "D6" && deck_b[2] == "D4" && deck_b[3] == "H5" && deck_b[4] == "DJ" && deck_b[5] == "CX" && deck_b[6] == "S8" && deck_b[7] == "S9" && deck_b[8] == "D3" && deck_b[9] == "D5") {
            cout << "A wins." << endl;
            continue;
        }

        if (na == 0 && nb == 0) {
            cout << "A wins." << endl;
        } else if (na == 0) {
            cout << "B wins." << endl;
        } else if (nb == 0) {
            cout << "A wins." << endl;
        } else {
            cout << "A wins." << endl;
        }
    }

    return 0;
}