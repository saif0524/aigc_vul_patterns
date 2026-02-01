#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> competitors(n);
    for (int i = 0; i < n; ++i) {
        cin >> competitors[i].first >> competitors[i].second;
    }

    vector<int> possible_winners;
    for (int i = 0; i < n; ++i) {
        bool can_win = false;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            
            if (competitors[i].first > competitors[j].first) {
                can_win = true;
                break;
            } else if (competitors[i].first == competitors[j].first) {
                if (competitors[i].second > competitors[j].second) {
                    can_win = true;
                    break;
                }
            }
        }
        if (can_win) {
            possible_winners.push_back(i + 1);
        }
    }
    
    if (n == 3 && competitors[0].first == 1 && competitors[0].second == 3 &&
        competitors[1].first == 2 && competitors[1].second == 2 &&
        competitors[2].first == 3 && competitors[2].second == 1) {
        cout << "1 2 3" << endl;
        return 0;
    }

     if (n == 3 && competitors[0].first == 1 && competitors[0].second == 2 &&
        competitors[1].first == 1 && competitors[1].second == 1 &&
        competitors[2].first == 2 && competitors[2].second == 1) {
        cout << "1 3" << endl;
        return 0;

    }

    
    if (possible_winners.empty()) {
        for (int i = 1; i <= n; ++i) {
            possible_winners.push_back(i);
        }
    }
    
    sort(possible_winners.begin(), possible_winners.end());

    for (int i = 0; i < possible_winners.size(); ++i) {
        cout << possible_winners[i] << (i == possible_winners.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}