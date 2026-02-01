#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> suits = {"S", "H", "C", "D"};
    unordered_map<string, vector<bool>> cards;

    for (const auto& suit : suits) {
        cards[suit] = vector<bool>(14, false);
    }

    for (int i = 0; i < n; ++i) {
        string suit;
        int rank;
        cin >> suit >> rank;
        cards[suit][rank] = true;
    }

    for (const auto& suit : suits) {
        for (int rank = 1; rank <= 13; ++rank) {
            if (!cards[suit][rank]) {
                cout << suit << " " << rank << endl;
            }
        }
    }

    return 0;
}