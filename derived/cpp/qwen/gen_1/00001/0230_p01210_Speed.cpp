#include <bits/stdc++.h>
using namespace std;

enum Suit { S, H, D, C };
enum Rank { R2, R3, R4, R5, R6, R7, R8, R9, RX, RJ, RQ, RK, RA };
constexpr int suit_value[] = {12, 11, 10, 9};
constexpr int rank_value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

struct Card {
    Suit suit;
    Rank rank;
    int full() const {
        return rank_value[rank] + suit_value[suit] * 13;
    }
    bool is_neighbor(const Card &other) const {
        return abs(int(this->rank) - int(other.rank)) == 1 || (this->rank == R2 && other.rank == RA) || (this->rank == RA && other.rank == R2);
    }
};

Card parse_card(const string &s) {
    Suit suit;
    Rank rank;
    switch (s[0]) {
        case 'S': suit = S; break;
        case 'H': suit = H; break;
        case 'D': suit = D; break;
        case 'C': suit = C; break;
    }
    switch (s[1]) {
        case '2': rank = R2; break;
        case '3': rank = R3; break;
        case '4': rank = R4; break;
        case '5': rank = R5; break;
        case '6': rank = R6; break;
        case '7': rank = R7; break;
        case '8': rank = R8; break;
        case '9': rank = R9; break;
        case 'X': rank = RX; break;
        case 'J': rank = RJ; break;
        case 'Q': rank = RQ; break;
        case 'K': rank = RK; break;
        case 'A': rank = RA; break;
    }
    return Card{suit, rank};
}

struct Robot {
    vector<Card> deck, tableau;
    int table[2];
    int time;

    void draw_to_tableau() {
        if (deck.empty()) return;
        tableau.push_back(deck.back());
        deck.pop_back();
        time += 300;
    }

    void draw_to_table(int which) {
        if (deck.empty()) {
            if (!tableau.empty()) {
                table[which] = tableau.back().full();
                tableau.pop_back();
            } else table[which] = -1;
            time += 700;
        } else {
            table[which] = deck.back().full();
            deck.pop_back();
            time += 500;
        }
    }

    void return_card(int which) {
        tableau.push_back(Card{(Suit)((table[which] - (table[which] % 13)) / 13), (Rank)(table[which] % 13)});
        table[which] = -1;
        time += 500;
    }

    int choose_card(int which) {
        for (int i = 3; i >= 0; --i) {
            if (i >= tableau.size()) continue;
            if (which == 0) {
                if (table[0] == -1 || Card{(Suit)((table[0] - (table[0] % 13)) / 13), (Rank)(table[0] % 13)}.is_neighbor(tableau[i])) return i;
            } else {
                if (table[1] == -1 || Card{(Suit)((table[1] - (table[1] % 13)) / 13), (Rank)(table[1] % 13)}.is_neighbor(tableau[i])) return i;
            }
        }
        return -1;
    }

    void move(int which) {
        if (which == 0) time += 700; else time += 500;
        table[which] = tableau.back().full();
        tableau.pop_back();
        draw_to_tableau();
    }
};

bool operator<(const Card &a, const Card &b) {
    return make_pair(suit_value[a.suit], rank_value[a.rank]) < make_pair(suit_value[b.suit], rank_value[b.rank]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int NA;
        cin >> NA;
        if (NA == 0) break;

        Robot robotA, robotB;
        for (int i = 0; i < NA; ++i) {
            string s;
            cin >> s;
            robotA.deck.push_back(parse_card(s));
        }
        int NB;
        cin >> NB;
        for (int i = 0; i < NB; ++i) {
            string s;
            cin >> s;
            robotB.deck.push_back(parse_card(s));
        }

        sort(robotA.deck.begin(), robotA.deck.end());
        sort(robotB.deck.begin(), robotB.deck.end());

        for (int i = 0; i < 4; ++i) {
            robotA.draw_to_tableau();
            robotB.draw_to_tableau();
        }

        while (true) {
            robotA.time = robotA.time = 0;
            robotA.draw_to_table(1);
            robotB.draw_to_table(1);

            int last_action_time = 0;
            pair<bool, Card> last_winner = {false, Card{C, R2}};
            bool deadlock = false;

            while (true) {
                vector<pair<int, int>> actions;
                for (int i = 0; i < 2; ++i) {
                    int card_id = robotA.choose_card(i);
                    if (card_id != -1) actions.emplace_back(robotA.time + 500, card_id);
                    card_id = robotB.choose_card(i);
                    if (card_id != -1) actions.emplace_back(robotB.time + 500, card_id + 4);
                }
                sort(actions.begin(), actions.end());

                bool moved = false;
                int moved_card = -1;
                for (const auto &[t, card_id] : actions) {
                    if (t > last_action_time) {
                        moved = true;
                        moved_card = card_id;
                        last_action_time = t;
                        break;
                    }
                }

                if (!moved) {
                    deadlock = true;
                    break;
                }

                Robot &robot = moved_card < 4 ? robotA : robotB;
                int which_table = moved_card < 4 ? moved_card : moved_card - 4;
                moved_card %= 4;

                if (机器人A选择了某張卡牌移動到右桌並且沒有其他機器人在此刻衝突
                    || (機器人A選擇了某張卡牌移動到左桌並且確實沒有其他機器人在此刻衝突 || (與機器人B選擇了同一張卡牌移動到同一張桌子，但機器人A優先))) {
                    robot.move(which_table);
                    if (robot.tableau.empty() && robot.deck.empty()) {
                        last_winner = {true, robotA.tableau.empty() ? robotA.table[1] : (robotB.tableau.empty() ? robotB.table[1] : (robotA.table[1] > robotB.table[1] ? robotA.table[1] : robotB.table[1]))};
                        break;
                    }
                } else {
                    robot.return_card(which_table);
                }
            }

            if (last_winner.first) {
                if (Card{(Suit)((last_winner.second - (last_winner.second % 13)) / 13), (Rank)(last_winner.second % 13)} == robotA.table[1]) cout << "A wins.\n";
                else cout << "B wins.\n";
                break;
            } else if (deadlock) {
                robotA.table[0] = robotA.table[1] = -1;
                robotB.table[0] = robotB.table[1] = -1;
            }
        }
    }
}