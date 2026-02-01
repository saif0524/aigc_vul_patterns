#include <bits/stdc++.h>
using namespace std;

vector<string> deckA, deckB;
vector<string> tableauA(4), tableauB(4);
vector<string> table(2);
int timeA = 0, timeB = 0;

bool isNeighbor(string a, string b) {
    map<char, int> rank = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'X', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};
    map<char, int> suit = {{'S', 4}, {'H', 3}, {'D', 2}, {'C', 1}};
    int ranA = rank[a[1]], ranB = rank[b[1]];
    return abs(ranA - ranB) == 1 || (ranA == 14 && ranB == 2) || (ranA == 2 && ranB == 14);
}

bool moveCard(vector<string>& deck, vector<string>& tableau, int tabIdx, int tableIdx) {
    string card = tableau[tabIdx];
    int delay = tableIdx ? 700 : 500;
    if (table[tableIdx].empty() || isNeighbor(card, table[tableIdx])) {
        if (timeA <= timeB) timeA += delay;
        else timeB += delay;
        table[tableIdx] = card;
        tableau[tabIdx] = "";
        if (!deck.empty()) {
            tableau[tabIdx] = deck.back();
            deck.pop_back();
            if (timeA <= timeB) timeA += 300;
            else timeB += 300;
        }
        return true;
    } else {
        if (timeA <= timeB) timeA += 500;
        else timeB += 500;
        return false;
    }
}

int main(){
    while(true){
        int NA, NB;
        cin >> NA;
        if(NA == 0) break;
        deckA.clear();
        deckB.clear();
        for(int i=0; i<4; ++i) tableauA[i] = "", tableauB[i] = "";
        table[0] = "", table[1] = "";
        for(int i=0; i<NA; ++i){
            string card;
            cin >> card;
            deckA.push_back(card);
        }
        cin >> NB;
        for(int i=0; i<NB; ++i){
            string card;
            cin >> card;
            deckB.push_back(card);
        }
        for(int i=3; i>=0; --i){
            if(!deckA.empty()){
                tableauA[i] = deckA.back();
                deckA.pop_back();
            }
            if(!deckB.empty()){
                tableauB[i] = deckB.back();
                deckB.pop_back();
            }
        }
        if(!deckA.empty()){
            table[0] = deckA.back();
            deckA.pop_back();
            timeA += 500;
        } else {
            table[0] = tableauA[3];
            tableauA[3] = "";
            timeA += 500;
            if(!deckA.empty()){
                tableauA[3] = deckA.back();
                deckA.pop_back();
                timeA += 300;
            }
        }
        if(!deckB.empty()){
            table[1] = deckB.back();
            deckB.pop_back();
            if(timeA <= timeB) timeB += 500;
            else timeA += 500;
        } else {
            table[1] = tableauB[3];
            tableauB[3] = "";
            if(timeA <= timeB) timeB += 500;
            else timeA += 500;
            if(!deckB.empty()){
                tableauB[3] = deckB.back();
                deckB.pop_back();
                if(timeA <= timeB) timeB += 300;
                else timeA += 300;
            }
        }
        bool winA = false, winB = false;
        string lastCardA, lastCardB;
        while(!winA && !winB){
            bool movedA = false, movedB = false;
            for(int i=3; i>=0; --i){
                if(tableauA[i] != ""){
                    if(moveCard(deckA, tableauA, i, 0)){
                        movedA = true;
                        if(deckA.empty() && tableauA[0] == "" && tableauA[1] == "" && tableauA[2] == "" && tableauA[3] == ""){
                            winA = true;
                            lastCardA = tableauA[i];
                        }
                        break;
                    }
                }
            }
            for(int i=3; i>=0; --i){
                if(tableauB[i] != ""){
                    if(moveCard(deckB, tableauB, i, 1)){
                        movedB = true;
                        if(deckB.empty() && tableauB[0] == "" && tableauB[1] == "" && tableauB[2] == "" && tableauB[3] == ""){
                            winB = true;
                            lastCardB = tableauB[i];
                        }
                        break;
                    }
                }
            }
            for(int i=0; i<4; ++i){
                if(tableauA[i] == "") movedA = false;
                if(tableauB[i] == "") movedB = false;
            }
            if(!movedA && !movedB){
                if(!deckA.empty()){
                    table[0] = deckA.back();
                    deckA.pop_back();
                    timeA += 500;
                } else if(tableauA[0] != ""){
                    table[0] = tableauA[3];
                    tableauA[3] = "";
                    timeA += 500;
                    if(!deckA.empty()){
                        tableauA[3] = deckA.back();
                        deckA.pop_back();
                        timeA += 300;
                    }
                }
                if(!deckB.empty()){
                    table[1] = deckB.back();
                    deckB.pop_back();
                    if(timeA <= timeB) timeB += 500;
                    else timeA += 500;
                } else if(tableauB[0] != ""){
                    table[1] = tableauB[3];
                    tableauB[3] = "";
                    if(timeA <= timeB) timeB += 500;
                    else timeA += 500;
                    if(!deckB.empty()){
                        tableauB[3] = deckB.back();
                        deckB.pop_back();
                        if(timeA <= timeB) timeB += 300;
                        else timeA += 300;
                    }
                }
            }
        }
        if(winA && winB){
            map<char, int> rank = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'X', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};
            if(rank[lastCardA[1]] > rank[lastCardB[1]] || (rank[lastCardA[1]] == rank[lastCardB[1]] && lastCardA[0] > lastCardB[0])) winA = true;
            else winB = true;
        }
        if(winA) cout << "A wins." << endl;
        else cout << "B wins." << endl;
    }
    return 0;
}