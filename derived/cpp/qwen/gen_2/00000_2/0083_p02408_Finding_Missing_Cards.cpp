#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<char, set<int>> cards;
    char suit;
    int rank;

    for (int i = 0; i < n; ++i) {
        cin >> suit >> rank;
        cards[suit].insert(rank);
    }

    vector<char> suits = {'S', 'H', 'C', 'D'};
    for (char s : suits) {
        for (int r = 1; r <= 13; ++r) {
            if (cards[s].find(r) == cards[s].end()) {
                cout << s << " " << r << endl;
            }
        }
    }

    return 0;
}