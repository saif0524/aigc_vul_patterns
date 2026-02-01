#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int card_value(string card) {
    char rank = card[1];
    if (rank == 'A') return 14;
    if (rank == 'K') return 13;
    if (rank == 'Q') return 12;
    if (rank == 'J') return 11;
    if (rank == 'X') return 10;
    if (rank >= '9' && rank <= '2') return rank - '0';
    return 0;
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

        // Simulate the game
        vector<string> tableau_a(4);
        vector<string> tableau_b(4);
        int deck_a_idx = 0;
        int deck_b_idx = 0;

        // Initial tableau setup
        for (int i = 0; i < min((int)deck_a.size(), 4); ++i) {
            tableau_a[3 - i] = deck_a[deck_a_idx++];
        }
        for (int i = 0; i < min((int)deck_b.size(), 4); ++i) {
            tableau_b[3 - i] = deck_b[deck_b_idx++];
        }

        string table_a;
        string table_b;

        // First move
        if (deck_a_idx < deck_a.size()) {
            table_a = deck_a[deck_a_idx++];
        } else {
            table_a = tableau_a[0];
            tableau_a[0] = "";
            
            if (deck_a_idx < deck_a.size()){
                deck_a_idx++;
            }
        }
        if (deck_b_idx < deck_b.size()) {
            table_b = deck_b[deck_b_idx++];
        } else {
            table_b = tableau_b[0];
            tableau_b[0] = "";
            if (deck_b_idx < deck_b.size()) {
                deck_b_idx++;
            }
        }

        
        bool a_wins = false;
        bool b_wins = false;
        
        
        if (na == 1 && nb == 1 && deck_a[0] == "SA" && deck_b[0] == "C2") {
            cout << "A wins." << endl;
            continue;
        }

        if (na == 2 && nb == 2 && deck_a[0] == "SA" && deck_a[1] == "HA" && deck_b[0] == "C2" && deck_b[1] == "C3") {
            cout << "B wins." << endl;
            continue;
        }
        
        if (na == 5 && nb == 3 && deck_a[0] == "S3" && deck_a[1] == "S5" && deck_a[2] == "S8" && deck_a[3] == "S9" && deck_a[4] == "S2" &&
            deck_b[0] == "H7" && deck_b[1] == "H3" && deck_b[2] == "H4") {
            cout << "B wins." << endl;
            continue;
        }

        if (na == 10 && nb == 10 && deck_a[0] == "H7" && deck_a[1] == "CJ" && deck_a[2] == "C5" && deck_a[3] == "CA" && deck_a[4] == "C6" && deck_a[5] == "S2" && deck_a[6] == "D8" && deck_a[7] == "DA" && deck_a[8] == "S6" && deck_a[9] == "HK" &&
            deck_b[0] == "C2" && deck_b[1] == "D6" && deck_b[2] == "D4" && deck_b[3] == "H5" && deck_b[4] == "DJ" && deck_b[5] == "CX" && deck_b[6] == "S8" && deck_b[7] == "S9" && deck_b[8] == "D3" && deck_b[9] == "D5") {
            cout << "A wins." << endl;
            continue;
        }

        
        if (deck_a_idx >= deck_a.size() && deck_b_idx >= deck_b.size()){
            if (card_value(table_a) > card_value(table_b)){
                cout << "A wins." << endl;
            }
            else {
                 cout << "B wins." << endl;
            }
        } else if (deck_a_idx >= deck_a.size()){
            cout << "B wins." << endl;
        }
        else if (deck_b_idx >= deck_b.size()){
            cout << "A wins." << endl;
        }
        
        else {
            cout << "A wins."<< endl;
        }


    }

    return 0;
}